class Solution {
public:
    bool isPalindrome(string s){
        string str= s;
        reverse(str.begin(),str.end());
        if(str==s){
            return true;
         } 
         else return false;
    }
    int countSubstrings(string s) {
        int cnt=0;
        //Make all substring
        for(int i=0;i<s.length();i++){
            string str="";
            for(int j=i;j<s.length();j++){
                str+=s[j];
                if(isPalindrome(str)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};