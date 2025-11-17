class Solution {
public:
    int first(vector<int>& nums,int x){
        int low=0,high=nums.size()-1,fo=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==x){
                fo=mid;
                high=mid-1;
            }
            else{
                if(nums[mid]<x){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return fo;
    }
    int last(vector<int>& nums,int x){
        int low=0,high=nums.size()-1,lo=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==x){
                lo=mid;
                low=mid+1;
            }
            else{
                if(nums[mid]<x){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f=first(nums,target);
        int l=last(nums,target);
        vector<int> v;
        v.push_back(f);
        v.push_back(l);
        return v;
    }
};