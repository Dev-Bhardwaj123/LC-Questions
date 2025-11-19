class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int low = 1, high = x / 2;
        int ans=0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long val = (long long) mid * mid;
            if(val<=x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans; 
    }
};