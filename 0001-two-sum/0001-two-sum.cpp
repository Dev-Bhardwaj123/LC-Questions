class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }
};

// ============================================================================
// PART 1: Configuration Modules and Inter-Thread Gateway Transport Structures
// ============================================================================
// #pragma once
// #include <opencv2/opencv.hpp>
// #include <opencv2/tracking.hpp>
// #include <opencv2/video.hpp>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <memory>
// #include <mutex>
// #include <atomic>
// #include <thread>
// #include <condition_variable>
// #include <algorithm>
// #include <cmath>
// #include <chrono>
// #include <cstdio>

// namespace cfg
// {
//     // Frame processing width resolution bounds
//     constexpr int    PROC_WIDTH = 640;

//     // Guardrail sizes for manual/single mouse clicks
//     constexpr int    DEFAULT_BOX_W = 85;
//     constexpr int    DEFAULT_BOX_H = 85;

//     // Confidence thresholds (combined NCC + color score, range 0..1)
//     constexpr double CONF_HIGH = 0.55; // accept + LEARN above this
//     constexpr double CONF_LOW  = 0.34; // accept (coast, NO learning) above this

//     // Frame allocation thresholds before triggering occlusion state routines
//     constexpr int    MAX_MEDIUM_FRAMES   = 30;  // medium-conf frames tolerated before LOST

//     // Adaptive template update rate (only applied on HIGH confidence)
//     constexpr double TEMPLATE_LR = 0.06;
//     constexpr double HIST_LR     = 0.05;

//     // Re-acquisition gates (must pass ALL to relock -> prevents locking onto impostors)
//     constexpr double REACQ_NCC      = 0.50; // template match score over canvas
//     constexpr double REACQ_HIST     = 0.55; // color histogram agreement
//     constexpr double REACQ_PEAK_GAP = 0.12; // best peak must beat 2nd-best by this (distinctiveness)

//     // Multi-scale search factors for re-detection (handles size change after occlusion)
//     constexpr double SCALE_MIN = 0.70;
//     constexpr double SCALE_MAX = 1.40;
//     constexpr int    SCALE_STEPS = 5;

//     // Motion gating
//     constexpr double MAX_JUMP_DIAG_MULT = 1.4; // candidate may move up to this * box-diagonal per frame
// }

// enum class Mode { IDLE, TRACKING, LOST };

// static const char* modeName(Mode m) noexcept
// {
//     switch (m) {
//     case Mode::IDLE:     return "IDLE - Click Target to Lock";
//     case Mode::TRACKING: return "TRACKING - Target Lock Confirmed";
//     case Mode::LOST:     return "LOST - Scanning Whole Canvas...";
//     }
//     return "?";
// }

// extern std::atomic<bool> g_running;
// extern cv::Mat           g_rawFrame;
// extern std::mutex        g_frameMtx;
// extern std::condition_variable g_frameCv;

// // ============================================================================
// // PART 2: Structural Geometry Preprocessing and Scale Mapping Layouts
// // ============================================================================
// class GeometryMapper {
// public:
//     static cv::Point2f centerOf(const cv::Rect& r) {
//         return { r.x + r.width * 0.5f, r.y + r.height * 0.5f };
//     }

//     static cv::Rect boxAtCenter(const cv::Point2f& center, const cv::Size& size) {
//         int x = (int)std::round(center.x - size.width * 0.5f);
//         int y = (int)std::round(center.y - size.height * 0.5f);
//         return cv::Rect(x, y, size.width, size.height);
//     }

//     static cv::Rect clamp(cv::Rect r, cv::Size sz) {
//         r.x = std::max(0, std::min(r.x, sz.width - 1));
//         r.y = std::max(0, std::min(r.y, sz.height - 1));
//         r.width = std::min(r.width, sz.width - r.x);
//         r.height = std::min(r.height, sz.height - r.y);
//         r.width = std::max(r.width, 10);
//         r.height = std::max(r.height, 10);
//         return r;
//     }

//     static cv::Rect scale(const cv::Rect& r, double factor) {
//         return cv::Rect(
//             (int)std::round(r.x * factor),
//             (int)std::round(r.y * factor),
//             (int)std::round(r.width * factor),
//             (int)std::round(r.height * factor)
//         );
//     }
// };

// // ============================================================================
// // PART 3: 4-State Constant Velocity Box Center Kalman Filter [X, Y, VX, VY Model]
// // ============================================================================
// class CenterKalmanFilter
// {
// public:
//     CenterKalmanFilter() { kf_.init(4, 2, 0, CV_32F); }

//     void reset(float cx, float cy)
//     {
//         kf_.transitionMatrix = (cv::Mat_<float>(4, 4) <<
//             1, 0, 1, 0,
//             0, 1, 0, 1,
//             0, 0, 1, 0,
//             0, 0, 0, 1);

//         kf_.measurementMatrix = cv::Mat::zeros(2, 4, CV_32F);
//         kf_.measurementMatrix.at<float>(0, 0) = 1.0f;
//         kf_.measurementMatrix.at<float>(1, 1) = 1.0f;

//         cv::setIdentity(kf_.processNoiseCov, cv::Scalar::all(1e-3));
//         kf_.processNoiseCov.at<float>(2, 2) = 1e-2f;
//         kf_.processNoiseCov.at<float>(3, 3) = 1e-2f;

//         cv::setIdentity(kf_.measurementNoiseCov, cv::Scalar::all(1e-1));
//         cv::setIdentity(kf_.errorCovPost, cv::Scalar::all(1.0));

//         kf_.statePost = (cv::Mat_<float>(4, 1) << cx, cy, 0.f, 0.f);
//         lastPred_ = { cx, cy };
//         primed_ = true;
//     }

//     cv::Point2f predict()
//     {
//         if (!primed_) return lastPred_;
//         cv::Mat prediction = kf_.predict();
//         lastPred_ = cv::Point2f(prediction.at<float>(0), prediction.at<float>(1));
//         return lastPred_;
//     }

//     void correct(const cv::Point2f& measurement)
//     {
//         cv::Mat m = (cv::Mat_<float>(2, 1) << measurement.x, measurement.y);
//         kf_.correct(m);
//     }

//     void freezeVelocity()
//     {
//         kf_.statePost.at<float>(2) = 0.0f;
//         kf_.statePost.at<float>(3) = 0.0f;
//         kf_.statePre.at<float>(2) = 0.0f;
//         kf_.statePre.at<float>(3) = 0.0f;
//     }

//     cv::Point2f lastPrediction() const { return lastPred_; }

//     float velocityMagnitude() const {
//         float vx = kf_.statePost.at<float>(2);
//         float vy = kf_.statePost.at<float>(3);
//         return std::sqrt(vx * vx + vy * vy);
//     }

// private:
//     cv::KalmanFilter kf_;
//     cv::Point2f      lastPred_{ 0.f, 0.f };
//     bool             primed_ = false;
// };

// // ============================================================================
// // PART 4: Appearance Verification Engine (template + color histogram)
// // ============================================================================
// // Keeps a small bank of grayscale templates (different stances) + an HSV
// // color histogram of the target. Both must be SATISFIED to confirm identity,
// // which is what stops the tracker from drifting onto another object.
// class AppearanceEngine {
// public:
//     AppearanceEngine() = default;

//     // hardReset: rebuild from scratch (on lock / relock). Otherwise gentle update.
//     // IMPORTANT: callers must ONLY update with high-confidence ROIs, never medium.
//     void updateTemplate(const cv::Mat& frame, const cv::Rect& roiIn, bool hardReset) {
//         cv::Rect roi = roiIn & cv::Rect(0, 0, frame.cols, frame.rows);
//         if (roi.width < 6 || roi.height < 6) return;

//         cv::Mat gray, patch;
//         cv::cvtColor(frame(roi), gray, cv::COLOR_BGR2GRAY);
//         gray.convertTo(patch, CV_32F);

//         if (hardReset || bank_.empty()) {
//             bank_.clear();
//             bank_.push_back(patch.clone());
//             baseSize_ = patch.size();
//         }
//         else {
//             // Compare against existing stances (resized to base size for fair NCC)
//             double bestNcc = -1.0;
//             int    bestIdx = 0;
//             cv::Mat pBase;
//             cv::resize(patch, pBase, baseSize_);
//             for (size_t i = 0; i < bank_.size(); ++i) {
//                 cv::Mat res;
//                 cv::matchTemplate(pBase, bank_[i], res, cv::TM_CCOEFF_NORMED);
//                 double v = res.at<float>(0, 0);
//                 if (v > bestNcc) { bestNcc = v; bestIdx = (int)i; }
//             }
//             if (bestNcc < 0.65 && bank_.size() < 4) {
//                 // genuinely new stance/perspective -> remember it
//                 bank_.push_back(pBase.clone());
//             }
//             else {
//                 // refine the closest stance gently
//                 cv::addWeighted(bank_[bestIdx], 1.0 - cfg::TEMPLATE_LR, pBase, cfg::TEMPLATE_LR, 0.0, bank_[bestIdx]);
//             }
//         }
//         updateHistogram(frame, roi, hardReset);
//     }

//     void updateHistogram(const cv::Mat& frame, const cv::Rect& roiIn, bool hardReset) {
//         cv::Rect roi = roiIn & cv::Rect(0, 0, frame.cols, frame.rows);
//         if (roi.width < 6 || roi.height < 6) return;
//         cv::Mat h = generateHist(frame(roi));
//         if (hardReset || hist_.empty()) {
//             hist_ = h;
//         }
//         else {
//             cv::addWeighted(hist_, 1.0 - cfg::HIST_LR, h, cfg::HIST_LR, 0.0, hist_);
//             cv::normalize(hist_, hist_, 1.0, 0.0, cv::NORM_L1);
//         }
//     }

//     // Combined identity score in [0,1]: 0.5*bestNCC + 0.5*colorSim.
//     double evaluateAppearance(const cv::Mat& frame, const cv::Rect& roiIn) const {
//         cv::Rect roi = roiIn & cv::Rect(0, 0, frame.cols, frame.rows);
//         if (bank_.empty() || roi.width < 6 || roi.height < 6) return 0.0;

//         cv::Mat gray, patch, pBase;
//         cv::cvtColor(frame(roi), gray, cv::COLOR_BGR2GRAY);
//         gray.convertTo(patch, CV_32F);
//         cv::resize(patch, pBase, baseSize_);

//         cv::Scalar mean, stddev;
//         cv::meanStdDev(pBase, mean, stddev);
//         if (stddev[0] < 3.0) return 0.0; // flat patch -> not our textured target

//         double maxNcc = 0.0;
//         for (const auto& t : bank_) {
//             cv::Mat result;
//             cv::matchTemplate(pBase, t, result, cv::TM_CCOEFF_NORMED);
//             double ncc = (double)result.at<float>(0, 0);
//             if (ncc > maxNcc) maxNcc = ncc;
//         }
//         double colorSim = evaluateHistSimilarity(frame, roi);
//         return 0.5 * std::max(0.0, maxNcc) + 0.5 * colorSim;
//     }

//     double evaluateHistSimilarity(const cv::Mat& frame, const cv::Rect& roiIn) const {
//         if (hist_.empty()) return 0.0;
//         cv::Rect clamped = roiIn & cv::Rect(0, 0, frame.cols, frame.rows);
//         if (clamped.width < 6 || clamped.height < 6) return 0.0;
//         cv::Mat currentHist = generateHist(frame(clamped));
//         return 1.0 - cv::compareHist(hist_, currentHist, cv::HISTCMP_BHATTACHARYYA);
//     }

//     // Full/region scan for re-detection. Tries multiple scales of the target so a
//     // size change during occlusion doesn't prevent relock. Returns best box, its
//     // combined score, and a peak-distinctiveness gap (best vs 2nd-best location).
//     bool searchRegion(const cv::Mat& frame, const cv::Rect& searchWinIn,
//                       const cv::Size& baseTargetSize,
//                       cv::Rect& bestBox, double& bestNccOut, double& peakGapOut) const
//     {
//         cv::Rect searchWin = searchWinIn & cv::Rect(0, 0, frame.cols, frame.rows);
//         if (bank_.empty() || searchWin.width < 12 || searchWin.height < 12) return false;

//         cv::Mat gray, searchSpace;
//         cv::cvtColor(frame(searchWin), gray, cv::COLOR_BGR2GRAY);
//         gray.convertTo(searchSpace, CV_32F);

//         double globalBest = -1.0;
//         double globalSecond = -1.0;
//         cv::Rect globalBox;

//         for (int s = 0; s < cfg::SCALE_STEPS; ++s) {
//             double f = cfg::SCALE_MIN +
//                        (cfg::SCALE_MAX - cfg::SCALE_MIN) * (cfg::SCALE_STEPS == 1 ? 0.0
//                        : (double)s / (cfg::SCALE_STEPS - 1));
//             cv::Size tSize((int)std::round(baseTargetSize.width * f),
//                            (int)std::round(baseTargetSize.height * f));
//             if (tSize.width < 8 || tSize.height < 8) continue;
//             if (tSize.width >= searchSpace.cols || tSize.height >= searchSpace.rows) continue;

//             for (const auto& t : bank_) {
//                 cv::Mat tpl;
//                 cv::resize(t, tpl, tSize);

//                 cv::Mat matchMap;
//                 cv::matchTemplate(searchSpace, tpl, matchMap, cv::TM_CCOEFF_NORMED);

//                 double minV, maxV; cv::Point minL, maxL;
//                 cv::minMaxLoc(matchMap, &minV, &maxV, &minL, &maxL);

//                 if (maxV > globalBest) {
//                     // demote previous best to "second" for distinctiveness measure
//                     globalSecond = globalBest;
//                     globalBest = maxV;
//                     globalBox = cv::Rect(searchWin.x + maxL.x, searchWin.y + maxL.y,
//                                          tSize.width, tSize.height);
//                 }
//                 else if (maxV > globalSecond) {
//                     globalSecond = maxV;
//                 }
//             }
//         }

//         if (globalBest < 0) return false;
//         bestBox = globalBox;
//         bestNccOut = globalBest;
//         peakGapOut = (globalSecond < 0) ? globalBest : (globalBest - globalSecond);
//         return true;
//     }

//     bool ready() const { return !bank_.empty() && !hist_.empty(); }