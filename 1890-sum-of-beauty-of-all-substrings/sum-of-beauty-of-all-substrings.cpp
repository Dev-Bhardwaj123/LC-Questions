class Solution {
public:
    int beautySum(string s) {
        unordered_map<char,int> mp;
        int res=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            for(int j=i+1;j<s.length();j++){
                mp[s[j]]++;
                int mini=INT_MAX;
                int maxi=INT_MIN;
                for(auto i:mp){
                    if(i.second>maxi){
                        maxi=i.second;
                    }
                    if(i.second<mini){
                        mini=i.second;
                    }
                }
                res+=maxi-mini;
            }
            mp.clear();
        }
        return res;
    }
};