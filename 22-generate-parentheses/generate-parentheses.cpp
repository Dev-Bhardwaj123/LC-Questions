class Solution {
public:
    void solve(int open,int close,string op,vector<string>& v){
        //base cond
        if(open==0 && close ==0){
            v.push_back(op);
            return;
        }
        //if open choice
        if(open!=0){
            string op1=op;
            op1.push_back('(');
            solve(open-1,close,op1,v);
        }
        //close choice
        if(close>open){
            string op2=op;
            op2.push_back(')');
            solve(open,close-1,op2,v);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        int open=n;
        int close=n;
        string op="";
        solve(open,close,op,s);
        return s;
    }
};