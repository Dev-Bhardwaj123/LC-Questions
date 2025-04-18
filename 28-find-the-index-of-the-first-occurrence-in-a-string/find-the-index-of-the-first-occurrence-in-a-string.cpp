class Solution {
public:
    vector<int> computeLPS(string needle){
        int n=needle.length();
        vector<int> lps(n,0);
        int len=0,i=1;
        while(i<n){
            if(needle[i]==needle[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        int m=haystack.length();
        int n=needle.length();
        vector<int> lps=computeLPS(needle);
        int i=0,j=0;
        while(i<m){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==n){
                return (i-j);
            }
            else if(i<m && haystack[i]!=needle[j]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};