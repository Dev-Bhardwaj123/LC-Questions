class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,maxlen=0;
        map<int,int> mp;

        while(r<fruits.size()){
            mp[fruits[r]]++;
            if(mp.size()>2){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0){
                        mp.erase(fruits[l]);
                    }
                    l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};