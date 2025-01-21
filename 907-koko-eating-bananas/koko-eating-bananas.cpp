class Solution {
public:
    bool isPoss(vector<int>& piles,int h,long long mid){
        int sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=ceil((double)piles[i]/mid);
            if(sum>h){
                return false;
            }
        }
        return sum<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low=1,high=piles[piles.size()-1];
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPoss(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};