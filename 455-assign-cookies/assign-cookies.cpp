class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt=0;
        int l=0,r=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(l<s.size() && r<g.size()){
            if(s[l]>=g[r]){
                cnt++;
                l++;
                r++;
            }
            else{
                l++;
            }
        }
        return cnt;
    }
};