class Solution {
public:
    string makeFancyString(string s) {
        string str="";
        str.push_back(s[0]);
        int cnt=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==str.back()){
                cnt++;
                if(cnt<3){
                    str.push_back(s[i]);
                }
            }
            else{
                cnt=1;
                str.push_back(s[i]);
            }
        }
        return str;
    }
};