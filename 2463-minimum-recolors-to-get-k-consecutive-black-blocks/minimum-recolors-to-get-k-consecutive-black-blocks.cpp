class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res=0,curr=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                curr++;
            }
        }
        res=curr;
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i]=='W')curr++;     
            if (blocks[i-k]=='W')curr--;  
            res=min(res, curr);
        }
        return res;
    }
};