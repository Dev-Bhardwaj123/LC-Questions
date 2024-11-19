class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0,maxSum=0;
        int i=0;
        unordered_set<int> s;
        for(int j=0;j<nums.size();j++){
            while(s.count(nums[j]) || s.size()==k){
                sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }
            sum+=nums[j];
            s.insert(nums[j]);

            if(s.size()==k){
                maxSum=max(maxSum,sum);
            }
        }
        return maxSum;
    }
};