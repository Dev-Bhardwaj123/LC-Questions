class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int pSum=nums[0];
        int i=1;
        while(i<n && nums[i]==nums[i-1]+1)
        {
            pSum+=nums[i];
            i++;
        }
        if(i==1) pSum+=1;
        unordered_set<int>st;
        while(i<n)
        {
            st.insert(nums[i]);
            i++;
        }
        while(1)
        {
            if(st.find(pSum)==st.end()) break;
            pSum++;
        }
        return pSum;
    }
};