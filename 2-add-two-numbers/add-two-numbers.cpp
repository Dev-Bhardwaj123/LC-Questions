/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        int total = 0, carry = 0;

        while (l1 || l2 || carry) {
            total = carry;

            if (l1) {
                total += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                total += l2->val;
                l2 = l2->next;
            }

            int num = total % 10;
            carry = total / 10;
            dummy->next = new ListNode(num);
            dummy = dummy->next;
        }

        ListNode* result = res->next;
        delete res;
        return result;
    }
};

// private:
//     cv::Mat generateHist(const cv::Mat& patchBgr) const {
//         cv::Mat hsv;
//         cv::cvtColor(patchBgr, hsv, cv::COLOR_BGR2HSV);
//         int channels[] = { 0, 1 };
//         int histSize[] = { 20, 20 };
//         float hRange[] = { 0, 180 };
//         float sRange[] = { 0, 256 };
//         const float* ranges[] = { hRange, sRange };

//         cv::Mat hist;
//         cv::calcHist(&hsv, 1, channels, cv::Mat(), hist, 2, histSize, ranges);
//         cv::normalize(hist, hist, 1.0, 0.0, cv::NORM_L1);
//         return hist;
//     }

//     std::vector<cv::Mat> bank_;       // grayscale stance templates, all at baseSize_
//     cv::Size             baseSize_{ 0, 0 };
//     cv::Mat              hist_;
// };

// // ============================================================================
// // PART 5: Production-Ready Hybrid Tracker Engine (CSRT core)
// // ============================================================================
// class DynamicHybridTrackerEngine {
// public:
//     DynamicHybridTrackerEngine() = default;

//     void initializeLock(const cv::Mat& frame, cv::Rect targetRoi) {
//         std::lock_guard<std::mutex> lock(mtx_);

//         if (targetRoi.width % 2 != 0) targetRoi.width++;
//         if (targetRoi.height % 2 != 0) targetRoi.height++;

//         box_ = GeometryMapper::clamp(targetRoi, frame.size());
//         baseSize_ = box_.size();   // reference size; CSRT may adapt the live box

//         appearance_.updateTemplate(frame, box_, true);
//         kalman_.reset(GeometryMapper::centerOf(box_).x, GeometryMapper::centerOf(box_).y);

//         allocateTracker(frame, box_);

//         mode_ = Mode::TRACKING;
//         confidence_ = 1.0;
//         consecMediumFrames_ = 0;
//         consecLostFrames_ = 0;
//     }

//     void processUpdate(const cv::Mat& frame) {
//         std::lock_guard<std::mutex> lock(mtx_);
//         if (mode_ == Mode::IDLE) return;

//         cv::Point2f predictedCenter = kalman_.predict();

//         if (mode_ == Mode::TRACKING) {
//             cv::Rect trackingResult = box_;
//             bool ok = nativeTracker_ && nativeTracker_->update(frame, trackingResult);

//             bool accepted = false;
//             if (ok) {
//                 trackingResult = GeometryMapper::clamp(trackingResult, frame.size());

//                 // Verify identity at the CSRT-proposed (tight) box -> max features.
//                 double score = appearance_.evaluateAppearance(frame, trackingResult);

//                 // Motion plausibility: reject teleports onto other objects.
//                 cv::Point2f candidateCenter = GeometryMapper::centerOf(trackingResult);
//                 double jump = cv::norm(candidateCenter - predictedCenter);
//                 double diag = std::sqrt((double)trackingResult.width * trackingResult.width +
//                                         (double)trackingResult.height * trackingResult.height);
//                 bool plausible = jump <= (cfg::MAX_JUMP_DIAG_MULT * diag + 2.0 * kalman_.velocityMagnitude());

//                 confidence_ = plausible ? score : 0.0;

//                 if (confidence_ >= cfg::CONF_HIGH) {
//                     // HIGH confidence: trust CSRT's tight box (keeps box on object,
//                     // exact size) and LEARN appearance here only.
//                     accepted = true;
//                     box_ = trackingResult;
//                     kalman_.correct(candidateCenter);
//                     consecMediumFrames_ = 0;
//                     appearance_.updateTemplate(frame, box_, false); // safe: high conf only
//                 }
//                 else if (confidence_ >= cfg::CONF_LOW) {
//                     // MEDIUM: keep coasting on CSRT box but DO NOT learn (avoids
//                     // poisoning the model with a half-off target).
//                     accepted = true;
//                     box_ = trackingResult;
//                     kalman_.correct(candidateCenter);
//                     if (++consecMediumFrames_ > cfg::MAX_MEDIUM_FRAMES) accepted = false;
//                 }
//             }

//             if (!accepted) {
//                 mode_ = Mode::LOST;
//                 consecLostFrames_ = 0;
//                 consecMediumFrames_ = 0;
//                 confidence_ = 0.0;
//                 nativeTracker_.release();
//                 std::cout << "[Occlusion/Drop] Lost target. Initiating full-canvas re-detection...\n";
//             }
//         }
//         else { // Mode::LOST -> verified re-acquisition
//             ++consecLostFrames_;
//             kalman_.freezeVelocity();

//             cv::Rect canvas(0, 0, frame.cols, frame.rows);

//             cv::Rect cand; double ncc = -1.0, gap = 0.0;
//             if (appearance_.searchRegion(frame, canvas, baseSize_, cand, ncc, gap)) {
//                 cand = GeometryMapper::clamp(cand, frame.size());
//                 double hist = appearance_.evaluateHistSimilarity(frame, cand);

//                 // Require strong template match AND color agreement AND a distinct
//                 // peak. All three together is what guarantees we relock the SAME
//                 // object and not a look-alike elsewhere in the frame.
//                 if (ncc >= cfg::REACQ_NCC && hist >= cfg::REACQ_HIST && gap >= cfg::REACQ_PEAK_GAP) {
//                     executeReacquisition(frame, cand, 0.5 * ncc + 0.5 * hist);
//                     return;
//                 }
//             }
//         }
//     }

//     void renderHud(cv::Mat& display, double scaleFactor) {
//         std::lock_guard<std::mutex> lock(mtx_);
//         if (mode_ == Mode::IDLE) return;

//         cv::Rect r = GeometryMapper::scale(box_, scaleFactor);
//         cv::Scalar renderColor;
//         std::string labelText;

//         if (mode_ == Mode::TRACKING) {
//             bool high = confidence_ >= cfg::CONF_HIGH;
//             renderColor = high ? cv::Scalar(0, 255, 0) : cv::Scalar(0, 140, 255);
//             labelText   = high ? "LOCK (CSRT)" : "LOCK (COASTING)";
//             cv::rectangle(display, r, renderColor, 2, cv::LINE_AA);
//             cv::circle(display, GeometryMapper::centerOf(r), 3, renderColor, cv::FILLED);
//         }
//         else {
//             renderColor = cv::Scalar(0, 0, 255);
//             labelText = "LOST - CANVAS RE-DETECTION";
//             cv::Rect ghost = GeometryMapper::scale(
//                 GeometryMapper::boxAtCenter(kalman_.lastPrediction(), baseSize_), scaleFactor);
//             cv::rectangle(display, ghost, renderColor, 1, cv::LINE_8);
//         }

//         char buffer[256];
//         std::snprintf(buffer, sizeof(buffer), "%s [%dx%d] Conf: %.2f",
//                       labelText.c_str(), r.width, r.height, confidence_);
//         cv::putText(display, buffer, cv::Point(r.x, std::max(18, r.y - 8)),
//                     cv::FONT_HERSHEY_SIMPLEX, 0.50, renderColor, 2, cv::LINE_AA);
//     }

//     Mode getEngineMode() { std::lock_guard<std::mutex> lock(mtx_); return mode_; }
//     void forceTermination() { std::lock_guard<std::mutex> lock(mtx_); mode_ = Mode::IDLE; nativeTracker_.release(); }

// private:
//     void executeReacquisition(const cv::Mat& frame, const cv::Rect& foundBox, double score) {
//         // Adopt the found box size+position directly so the box hugs the object
//         // (it may have changed scale during the occlusion).
//         box_ = GeometryMapper::clamp(foundBox, frame.size());
//         baseSize_ = box_.size();

//         kalman_.reset(GeometryMapper::centerOf(box_).x, GeometryMapper::centerOf(box_).y);
//         allocateTracker(frame, box_);

//         mode_ = Mode::TRACKING;
//         confidence_ = score;
//         consecMediumFrames_ = 0;
//         // Reinforce model gently with the confirmed re-detection (high-confidence event)
//         appearance_.updateTemplate(frame, box_, false);
//         std::cout << "[Relock Confirmed] Target re-locked (score " << score << ").\n";
//     }

//     void allocateTracker(const cv::Mat& frame, const cv::Rect& roi) {
//         // CSRT only: it adapts box scale (tight boxes / max features) and tolerates
//         // rotation far better than KCF, eliminating the size-mismatch + drift issues.
//         nativeTracker_ = cv::TrackerCSRT::create();
//         nativeTracker_->init(frame, GeometryMapper::clamp(roi, frame.size()));
//     }

//     Mode                 mode_ = Mode::IDLE;
//     cv::Rect             box_{ 0, 0, cfg::DEFAULT_BOX_W, cfg::DEFAULT_BOX_H };
//     cv::Size             baseSize_{ cfg::DEFAULT_BOX_W, cfg::DEFAULT_BOX_H };
//     double               confidence_ = 0.0;

//     int                  consecMediumFrames_ = 0;
//     int                  consecLostFrames_ = 0;

//     cv::Ptr<cv::Tracker> nativeTracker_;
//     CenterKalmanFilter   kalman_;
//     AppearanceEngine     appearance_;
//     std::mutex           mtx_;
// };

// // ============================================================================
// // PART 6: Asynchronous Ingestion Thread Workers
// // ============================================================================
// struct MouseEventBlock {
//     std::atomic<bool> pending{ false };
//     cv::Point         pt;
//     std::mutex        mtx;
// };

// static void onMouseCallback(int event, int x, int y, int, void* userdata)
// {
//     if (event == cv::EVENT_LBUTTONDOWN) {
//         auto* cb = static_cast<MouseEventBlock*>(userdata);
//         std::lock_guard<std::mutex> lock(cb->mtx);
//         cb->pt = cv::Point(x, y);
//         cb->pending = true;
//     }
// }

// void frameCaptureWorker(cv::VideoCapture* captureLink) {
//     cv::Mat internalFrame;
//     while (g_running.load(std::memory_order_relaxed)) {
//         if (captureLink->grab()) {
//             if (captureLink->retrieve(internalFrame) && !internalFrame.empty()) {
//                 std::lock_guard<std::mutex> lock(g_frameMtx);
//                 g_rawFrame = internalFrame.clone();
//                 g_frameCv.notify_one();
//             }
//         }
//         else {
//             std::this_thread::sleep_for(std::chrono::milliseconds(4));
//         }
//     }
// }

// // ============================================================================
// // PART 7: Application Entry Point and High-Speed Orchestration Loop
// // ============================================================================
// std::atomic<bool> g_running(true);
// cv::Mat           g_rawFrame;
// std::mutex        g_frameMtx;
// std::condition_variable g_frameCv;

// int main(int argc, char** argv)
// {
// #ifdef _WIN32
//     _putenv("OPENCV_FFMPEG_CAPTURE_OPTIONS=protocol_whitelist;file,rtp,udp,data");
// #else
//     setenv("OPENCV_FFMPEG_CAPTURE_OPTIONS", "protocol_whitelist;file,rtp,udp,data", 1);
// #endif

//     cv::VideoCapture cap;
//     std::string videoSource =
//         "data:application/sdp,"
//         "v=0\r\n"
//         "o=- 0 0 IN IP4 127.0.0.1\r\n"
//         "s=FFmpeg Production Live RTP\r\n"
//         "c=IN IP4 127.0.0.1\r\n"
//         "t=0 0\r\n"
//         "m=video 1234 RTP/AVP 96\r\n"
//         "a=rtpmap:96 H264/90000\r\n";

//     std::cout << "==================================================================\n";
//     std::cout << "  [HYBRID TRACKER INITIALIZATION] Starting Occlusion Pipeline...\n";
//     std::cout << "==================================================================\n\n";

//     int linkAttempts = 0;
//     while (!cap.isOpened()) {
//         cap.open(videoSource, cv::CAP_FFMPEG);
//         if (!cap.isOpened()) {
//             linkAttempts++;
//             std::cout << "[Network Ingestion] Connecting to stream source (Attempt " << linkAttempts << ")... \n";
//             std::this_thread::sleep_for(std::chrono::milliseconds(500));
//             if (linkAttempts > 5) {
//                 std::cout << "[Fallback Link] Opening standard local camera device interface...\n";
//                 cap.open(0);
//                 break;
//             }
//         }
//     }
//     cap.set(cv::CAP_PROP_BUFFERSIZE, 1);

//     const std::string title = "Dynamic Hybrid Tracker (Green=Lock / Orange=Coasting / Red=Lost)";
//     cv::namedWindow(title, cv::WINDOW_AUTOSIZE);

//     MouseEventBlock mouseBlock;
//     cv::setMouseCallback(title, onMouseCallback, &mouseBlock);

//     std::thread structuralInferenceThread(frameCaptureWorker, &cap);

//     DynamicHybridTrackerEngine engine;
//     cv::Mat processingCanvas, activeWorkingFrame;
//     double operationalFps = 0.0;
//     cv::TickMeter processingStopwatch;
//     char textHudBuffer[256];

//     while (g_running.load(std::memory_order_relaxed)) {
//         processingStopwatch.reset();
//         processingStopwatch.start();

//         {
//             std::unique_lock<std::mutex> frameLock(g_frameMtx);
//             g_frameCv.wait(frameLock, [] { return !g_rawFrame.empty() || !g_running; });
//             if (!g_running) break;
//             processingCanvas = g_rawFrame.clone();
//         }

//         const double scaleFactor = static_cast<double>(processingCanvas.cols) / cfg::PROC_WIDTH;
//         cv::resize(processingCanvas, activeWorkingFrame,
//             cv::Size(cfg::PROC_WIDTH, static_cast<int>(processingCanvas.rows / scaleFactor)),
//             0, 0, cv::INTER_AREA);

//         if (mouseBlock.pending) {
//             mouseBlock.pending = false;
//             cv::Point clickPt;
//             {
//                 std::lock_guard<std::mutex> lock(mouseBlock.mtx);
//                 clickPt = mouseBlock.pt;
//             }

//             cv::Point mappedCoord(static_cast<int>(clickPt.x / scaleFactor),
//                                   static_cast<int>(clickPt.y / scaleFactor));

//             if (mappedCoord.x >= 1 && mappedCoord.x < activeWorkingFrame.cols - 1 &&
//                 mappedCoord.y >= 1 && mappedCoord.y < activeWorkingFrame.rows - 1)
//             {
//                 // Flood fill to snap a tight box around the clicked object so the
//                 // initial bounding box matches object size (captures max features).
//                 cv::Mat segmentMask = cv::Mat::zeros(activeWorkingFrame.rows + 2,
//                                                      activeWorkingFrame.cols + 2, CV_8UC1);
//                 cv::Rect boundingBoxOutput;

//                 cv::floodFill(activeWorkingFrame, segmentMask, mappedCoord, cv::Scalar(0, 0, 0),
//                     &boundingBoxOutput,
//                     cv::Scalar(15, 15, 15), cv::Scalar(15, 15, 15),
//                     4 | cv::FLOODFILL_MASK_ONLY | (255 << 8));

//                 if (boundingBoxOutput.width < 15 || boundingBoxOutput.height < 15 ||
//                     boundingBoxOutput.width > activeWorkingFrame.cols * 0.75 ||
//                     boundingBoxOutput.height > activeWorkingFrame.rows * 0.75)
//                 {
//                     boundingBoxOutput = cv::Rect(mappedCoord.x - cfg::DEFAULT_BOX_W / 2,
//                         mappedCoord.y - cfg::DEFAULT_BOX_H / 2,
//                         cfg::DEFAULT_BOX_W, cfg::DEFAULT_BOX_H);
//                 }
//                 engine.initializeLock(activeWorkingFrame, boundingBoxOutput);
//             }
//         }

//         engine.processUpdate(activeWorkingFrame);
//         engine.renderHud(processingCanvas, scaleFactor);

//         processingStopwatch.stop();
//         operationalFps = 0.9 * operationalFps + 0.1 * (1000.0 / std::max(processingStopwatch.getTimeMilli(), 1.0));

//         std::snprintf(textHudBuffer, sizeof(textHudBuffer), "Pipeline: %s | Rendering Engine: %.0f FPS",
//             modeName(engine.getEngineMode()), operationalFps);
//         cv::putText(processingCanvas, textHudBuffer, cv::Point(12, 24),
//                     cv::FONT_HERSHEY_SIMPLEX, 0.60, cv::Scalar(255, 255, 255), 2, cv::LINE_AA);

//         cv::imshow(title, processingCanvas);

//         int triggerKey = cv::waitKey(1) & 0xFF;
//         if (triggerKey == 'q' || triggerKey == 27) break;
//         if (triggerKey == 'c') engine.forceTermination();
//     }

//     g_running = false;
//     g_frameCv.notify_all();

//     if (structuralInferenceThread.joinable()) structuralInferenceThread.join();

//     cap.release();
//     cv::destroyAllWindows();
//     return 0;
// }