class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int sec=INT_MIN;
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<sec){
                return true;
            }
            while(!st.empty() && nums[i]>st.top()){
                sec=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};