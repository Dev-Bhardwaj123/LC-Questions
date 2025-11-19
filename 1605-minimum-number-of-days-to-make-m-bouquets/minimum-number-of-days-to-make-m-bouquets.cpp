class Solution {
public:
    bool isPoss(vector<int>& bloomDay, int m,int k,int mid){
        int nb=0;
        int cnt=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                nb+=(cnt/k);
                cnt=0;
            }
        }
        nb+=(cnt/k);
        return nb>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val=(long long)m*(long long)k;
        if(val>n) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPoss(bloomDay,m,k,mid)){
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