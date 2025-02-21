class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
          sort(intervals.begin(),intervals.end()); //sort intervals by start time
          int k=0;// index of merged interval
          for(int i=1;i<intervals.size();i++){
            if(intervals[k][1]>=intervals[i][0]){ //overlap found
                intervals[k][1]=max(intervals[k][1],intervals[i][1]); //merge
            }
            else{
                k++;
                intervals[k]=intervals[i]; //move next and replace in place
            }
          }
          intervals.resize(k+1); //adjust size to only include merged ones
          return intervals;
    }
};