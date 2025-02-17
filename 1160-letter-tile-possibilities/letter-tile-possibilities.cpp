class Solution {
public:
    int backtrack(string& tiles,vector<bool>& used){
        int cnt=0;
        for(int i=0;i<tiles.size();i++){
            if(used[i] || (i>0 && tiles[i]==tiles[i-1]) && !used[i-1]){
                continue;
            }
            used[i]=true;
            cnt+=1+backtrack(tiles,used);
            used[i]=false;
        }
        return cnt;
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        vector<bool> used(tiles.size(),false);
        return backtrack(tiles,used);
    }
};