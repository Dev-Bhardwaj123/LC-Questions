class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char,int> mp;
        for(int i=0;i<s1.length();i++){
            mp[s1[i]]++;
        }
        for(int j=0;j<s2.length();j++){
            mp[s2[j]]--;
        }
        for(auto k:mp){
            if(k.second!=0){
                return false;
            }
        }
        int cnt=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                cnt++;
            }
        }
        return (cnt==0 || cnt==2)? true: false;
    }
};