class Solution {
public:
    bool isRiyal(vector<int>& prices,int k,int n,int mid){
        int prev=prices[0];
        k--;
        for(int i=1;i<prices.size();i++){
            if(k==0){
                break;
            }
            if(prices[i]-prev>=mid){
                prev=prices[i];
                k--;
            }
        }
        return k==0;
    }
    int maximumTastiness(vector<int>& prices, int k) {
        sort(prices.begin(),prices.end());
        int low=0,high=prices[prices.size()-1]-prices[0];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isRiyal(prices,k,prices.size(),mid)){
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