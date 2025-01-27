class Solution {
public:
    int helper(int n,bool lToR){
        if(n==1){
            return true;
        }
        if(lToR){
            return 2*helper(n/2,false);
        }
        else{
            if(n%2==0){
                return 2*helper(n/2,true)-1;
            }
            else{
                return 2*helper(n/2,true);
            }
        }
    }
    int lastRemaining(int n) {
        return helper(n,true);
    }
};