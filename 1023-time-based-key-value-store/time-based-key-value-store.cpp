class TimeMap {
public:

    map<string,vector<pair<string,int>>> mp;

    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";
            
        vector<pair<string,int>> &v = mp[key];

        int low = 0, high = v.size() - 1;
        string res = "";

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (v[mid].second <= timestamp) {
                res = v[mid].first;   // Possible answer
                low = mid + 1;        // Look for a larger valid timestamp
            } else {
                high = mid - 1;
            }
        }
        return res;
    }

};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */