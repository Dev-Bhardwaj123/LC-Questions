class Solution {
public:
    bool isPoss(vector<int>& piles, int h,int k){
        int total=0;
        for(int i=0;i<piles.size();i++){
            total+=ceil((double)piles[i]/k);
            if(total>h){
                return false;
            }
        }
        return total<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int low=1,high=piles[n-1];
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPoss(piles,h,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};