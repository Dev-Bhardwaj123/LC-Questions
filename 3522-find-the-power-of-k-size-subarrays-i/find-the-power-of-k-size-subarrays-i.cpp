class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> v;
        for(int i=0;i<=nums.size()-k;i++){
            int z;
            bool flag=true;
            for(int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    flag = false;
                    break;
                }
            }
            if(flag==true){
                z=*max_element(nums.begin()+i,nums.begin()+i+k);
            }
            else{
                z=-1;
            }
            v.push_back(z);
        }
        return v;
    }
};