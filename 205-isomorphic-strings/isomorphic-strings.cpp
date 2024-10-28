class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,bool>mp2;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i]){
                    return 0;
                }
                else{
                    continue;
                }
            }
            else{
                if(mp2[t[i]])return 0;
                mp[s[i]]=t[i];
                mp2[t[i]]=1;
            }

        }
        return 1;
    }
};