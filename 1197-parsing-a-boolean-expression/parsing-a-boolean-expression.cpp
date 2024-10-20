class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char c:expression){
            if(c!=')' && c!=','){
                st.push(c);
            }
            else if(c==')'){
                vector<bool> exp;
                while(!st.empty() && st.top()!='('){
                    char t=st.top();
                    st.pop();
                    if(t=='t'){
                        exp.push_back(true);
                    }
                    else{
                        exp.push_back(false);
                    }
                }
                st.pop(); //pops '(' from stack
                if(!st.empty()){
                    char t=st.top();
                    st.pop();
                    bool v=exp[0];
                    if(t=='&'){
                        for(bool b:exp){
                            v&=b;
                        }
                    }
                    else if(t=='|'){
                        for(bool b:exp){
                            v|=b;
                        }
                    }
                    else{
                        v=!v;
                    }
                    if(v){
                        st.push('t');
                    }
                    else{
                        st.push('f');
                    }
                }
            }
        }
        return st.top()=='t'? true: false;
    }
};