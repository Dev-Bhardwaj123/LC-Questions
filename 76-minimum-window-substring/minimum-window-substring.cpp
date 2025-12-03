class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        vector<int> hash(256,0);
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        int l=0,r=0,cnt=0,minlen=INT_MAX,sInd=-1;
        while(r<n){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sInd=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt-=1;
                l++;
            }
            r++;
        }
        return sInd==-1? "" : s.substr(sInd,minlen);
    }
};