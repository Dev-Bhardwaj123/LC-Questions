class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> vec;
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--){
            while(st.empty()==false && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(st.empty()==false && temperatures[st.top()]>=temperatures[i] ){
                vec.push_back(abs(st.top()-i));
            }
            else if(st.empty()){
                vec.push_back(0);
            }
            st.push(i);
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};