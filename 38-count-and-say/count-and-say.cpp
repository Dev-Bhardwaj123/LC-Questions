class Solution {
public:
    string countAndSay(int n1) {
        if(n1==1) return "1";
        string str=countAndSay(n1-1);
        int n=str.size();
        int count=1;
        string temp="";
        for(int i=n-1;i>0;i--){
            if(str[i]!=str[i-1]){
                temp=to_string(count)+str[i]+temp;
                count=1;
            }
            else{
                count++;
            }
        }
        temp=to_string(count)+str[0]+temp;
        return temp;
    }
};