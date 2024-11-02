class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0]!=sentence[sentence.length()-1]){
            return false;
        }
        bool flag=true;
        for(int i=1;i<sentence.length();i++){
            if(sentence[i]==' '){
                if(sentence[i-1]!=sentence[i+1]){
                    flag=false;
                }
            }
        }
        return flag;
    }
};