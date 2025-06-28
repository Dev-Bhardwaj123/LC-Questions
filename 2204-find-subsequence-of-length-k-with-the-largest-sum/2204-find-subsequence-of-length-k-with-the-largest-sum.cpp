class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        for(auto i:vec){
            cout<<i.first<<" "<<i.second<<endl;
        }
        vector<int> ans;
        for(int i=vec.size()-1;i>=0;i--){
            if(k==0){
                break;
            }
            ans.push_back(vec[i].second);
            k--;
        }
        sort(ans.begin(),ans.end());
        vector<int> res;
        for(int i=0;i<ans.size();i++){
            res.push_back(nums[ans[i]]);
        }
        return res;
    }
};