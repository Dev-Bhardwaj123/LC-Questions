class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>arr;
        arr.push_back(meetings[0]);
        for(int j=1;j<meetings.size();j++){
            if(meetings[j][0]<=arr.back()[1]){
                arr.back()[1]=max(arr.back()[1],meetings[j][1]);
            }
            else{
                arr.push_back(meetings[j]);
            }
        }
        int count=0;
        for(int i=0;i<arr.size();i++){
           count+=(arr[i][1]-arr[i][0]+1);
        }
        return (days-count);
    }
};