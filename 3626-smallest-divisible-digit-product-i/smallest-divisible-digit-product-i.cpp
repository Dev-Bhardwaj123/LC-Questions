class Solution {
public:
    int prod(int x){
        int mul=1;
        while(x>0){
            int r=x%10;
            mul*=r;
            x=x/10;
        }
        return mul;
    }
    int smallestNumber(int n, int t) {
        int res=0;
        int i=n;
        while(i<=n*t){
            int p=prod(i);
            if(p%t==0){
                res=i;
                break;
            }
            i++;
        }
        return res;
    }
};