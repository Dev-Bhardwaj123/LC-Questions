class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int l=0,r=height.size()-1;
        int lmax=0,rmax=height[r];
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]<lmax){
                    res+=lmax-height[l];
                }
                else{
                    lmax=height[l];
                }
                l++;
            }
            else{
                if(height[r]<rmax){
                    res+=rmax-height[r];
                }
                else{
                    rmax=height[r];
                }
                r--;
            }
        }
        return res;
    }
};