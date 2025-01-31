class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='c'){
                if(st.size()<2) return false;
                else{
                    if(st.top()!='b'){
                        return false;
                    }
                    else st.pop();
                    if(st.top()!='a') return false;
                    else st.pop();
                }
            }
            else{
                st.push(ch);
            }
        }
        return st.empty();

    }
};