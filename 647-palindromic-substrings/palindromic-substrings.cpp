class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length(),ans=0;
        for(int i=0;i<n;i++){
            int even=palindromeCount(s,i,i+1);
            int odd=palindromeCount(s,i,i);
            ans+=even+odd;
        }
        return ans;
    }
    int palindromeCount(const string& s,int left,int right){
        int cnt=0;
        while(left>=0 && right<s.length() && s[left]==s[right]){
            --left;
            ++right;
            ++cnt;
        }
        return cnt;
    }
};