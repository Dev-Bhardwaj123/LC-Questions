class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        long long res=0;
        while(i<=j){
            long long  w=j-i;
            long long l=min(height[i],height[j]);
            res=max(res,l*w);
            if(height[i]<=height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return res;
    }
};