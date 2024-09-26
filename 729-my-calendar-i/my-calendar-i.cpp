class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int,int>> ranges;
    bool book(int start, int end) {
        for(auto const& pair:ranges){
            int st=pair.first;
            int en=pair.second;
            if(start<en && end>st){
                return false;
            }
        }
        ranges.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */