class Solution {
public:
    bool checkValid(vector<int>& position,int k,int mid){
        int prev=position[0];
        k--;
        for(int i=1;i<position.size();i++){
            if(k==0){
                break;
            }
            else if(position[i]-prev>=mid){
                prev=position[i];
                k--;
            }
        }
        return k==0;
    }
    int maxDistance(vector<int>& position, int m) {
        int ans=0;
        sort(position.begin(),position.end());
        int low=0,high=position[position.size()-1]-position[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(checkValid(position,m,mid)){
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