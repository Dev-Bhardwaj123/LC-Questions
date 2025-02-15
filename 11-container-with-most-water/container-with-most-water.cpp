class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int i=0,j=height.size()-1;
        while(i<j){
            int w=j-i;
            int h=min(height[i],height[j]);
            int curr=w*h;
            res=max(res,curr);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return res;
    }
};