class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                char ch=tolower(s[i]);
                str+=ch;
            }
            else{
                continue;
            }
        }
        cout<<str;
        int i=0,j=str.length()-1;
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

    }
};