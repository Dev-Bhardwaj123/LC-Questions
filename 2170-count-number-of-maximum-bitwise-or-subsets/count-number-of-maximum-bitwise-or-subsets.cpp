class Solution {
public:
    void solve(const vector<int> &nums,int index,int currOR,int maxOR,int &count)
    {
        if (currOR == maxOR)
        {
            count++;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            solve(nums, i + 1,currOR | nums[i],maxOR,count);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for (int num : nums)
        {
            maxOR |= num;
        }
        int count = 0;
        solve(nums, 0, 0, maxOR, count);
        return count;
    }
};