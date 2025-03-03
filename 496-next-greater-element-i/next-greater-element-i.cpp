class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> temp;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            if(!s.empty() && s.top()>=nums2[i]){
                ans.push_back(s.top());
            }
            s.push(nums2[i]);
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    temp.push_back(ans[j]);
                }
            }
        }
        return temp;
    }
};