class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int res=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push('(');
            }
            if(s[i]==')'){
                st.pop();
            }
            int cnt=st.size();
            res=max(res,cnt);
        }
        return res;
    }
};