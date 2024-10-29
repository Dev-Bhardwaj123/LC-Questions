class Solution {
public:
    static bool cmp(pair<char, int>& a,pair<char, int>& b) 
    { 
        return a.second>b.second; 
    } 
    void sorti(map<char,int>& mp,string& str){
        vector<pair<char,int>> vec;
        for(auto it:mp){
            vec.push_back(it);
        }
        sort(vec.begin(),vec.end(),cmp);
        for(auto it:vec){
            str+=string(it.second,it.first);
        }
    }
    string frequencySort(string s) {
        string str="";
        map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        sorti(mp,str);
        return str;
    }
};