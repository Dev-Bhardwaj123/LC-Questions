class Solution {
public:
    vector<int> preXOR(vector<int>& nums){
        vector<int> v(nums.size());
        v[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            v[i]=v[i-1]^nums[i];
        }
        return v;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> prefixXOR;
        int k=pow(2,maximumBit);
        prefixXOR=preXOR(nums);
        vector<int> res;
         for(int i = prefixXOR.size() - 1; i >= 0; i--){
            int maxXor = (k - 1) ^ prefixXOR[i];
            res.push_back(maxXor);
        }
        return res;

    }
};