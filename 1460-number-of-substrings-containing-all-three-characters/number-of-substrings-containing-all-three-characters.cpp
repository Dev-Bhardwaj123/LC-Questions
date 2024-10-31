class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last_seen={-1,-1,-1};
        int cnt=0;
        for(int i=0;i<s.length();i++){
            last_seen[s[i]-'a']=i;
            cnt+=1+min(last_seen[0],min(last_seen[1],last_seen[2]));
        }
        return cnt;
    }
};