class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        multiset<int> st; 
        int i=0,j=0;
        long long ans=0;
        
        while(i<n){
            while(j<n && (st.size()==0 || max(nums[j],*(--st.end()))-min(*st.begin(),nums[j])<=2)){
                st.insert(nums[j]);
                j++;
            }
            ans+= st.size();
            st.erase(st.find(nums[i]));
            i++;
        }
        return ans;
    }
};