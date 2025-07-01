class Solution {
public:
    int possibleStringCount(string word) {
        int cnt=1;
        int n=word.length()-1;
        for(int i=n-1;i>=0;i--){
            if(word[i]==word[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};