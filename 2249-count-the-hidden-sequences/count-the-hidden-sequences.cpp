class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mx=0;
        long long mn=0;
        long long sum=0;
        for(int i=0;i<differences.size();i++){
            sum+=differences[i];
            mn=min(sum,mn);
            mx=max(sum,mx);
        }
        return max(0LL,(upper-lower)-(mx-mn) + 1);
    }
};