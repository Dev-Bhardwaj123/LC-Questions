class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int st=0,end=skill.size()-1;
        long long res=0;
        long long p=skill[0]+skill[end];
        while(st<=end){
            if(skill[st]+skill[end]!=p){
                return -1;
            }
            res+=skill[st]*skill[end];
            st++;
            end--;
        }
        return res;
    }
};