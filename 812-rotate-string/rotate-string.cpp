class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.size()){
            return 0;
        }
        string res=s;
        res+=s;
        return res.find(goal)!=string::npos;

    }
};