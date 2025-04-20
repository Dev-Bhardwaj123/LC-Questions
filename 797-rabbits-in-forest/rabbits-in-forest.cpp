class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int i=0;i<answers.size();i++){
            mp[answers[i]]++;
        }
        int cnt=0;
        for(auto m:mp){
            int gSize=m.first+1;
            int grps=ceil((double)m.second/gSize);
            cnt+=grps*gSize;
        }
        return cnt;
    }
};