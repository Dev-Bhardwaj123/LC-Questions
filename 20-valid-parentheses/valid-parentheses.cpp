class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(!st.empty()&&((st.top()=='(' && s[i]==')')||(st.top()=='[' && s[i]==']')||(st.top()=='{' && s[i]=='}'))){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        return st.empty();
    }
};