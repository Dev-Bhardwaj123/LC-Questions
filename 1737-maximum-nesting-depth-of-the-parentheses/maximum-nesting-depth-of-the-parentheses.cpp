class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            if(s[i]==')'){
                st.pop();
            }
            int res=st.size();
            cnt=max(cnt,res);
        }
        return cnt;
    }
};