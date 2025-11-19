class Solution {
public:
    bool isPoss(vector<int>& weights,int days,int cap){
        int dtrack=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>cap){
                dtrack+=1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return dtrack<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPoss(weights,days,mid)){
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