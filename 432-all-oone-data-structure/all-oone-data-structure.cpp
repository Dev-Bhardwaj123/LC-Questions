class AllOne {
public:
    unordered_map<string,int> count;  
    set<pair<int,string>> se;        
    
    AllOne() {
        count.clear(); 
    }
    void inc(string key) {
        int n = count[key];   
        count[key]++;         // Increment the count
        se.erase({n, key});   // Remove the old pair from set
        se.insert({n+1, key}); 
    }
    void dec(string key) {
        int n = count[key];   
        count[key]--;         // Decrement the count
        se.erase({n, key});   
        if (count[key] > 0) se.insert({n-1, key});  // If count > 0, insert updated pair
        else count.erase(key);  // If count reaches 0, remove the key from map
    }
    string getMaxKey() {
        if (!se.empty()) return se.rbegin()->second;  // Last element gives the maximum
        return "";
    }

    // Get the key with the minimum count
    string getMinKey() {
        if (!se.empty()) return se.begin()->second;  // First element gives the minimum
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */