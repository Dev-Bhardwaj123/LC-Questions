class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(N==0){
            return 1;
        }
        if(N<0){
            x=1/x;
            N=-N;
        }
        double temp=myPow(x,N/2);
        temp=temp*temp;
        if(N%2==0){
            return temp;
        }
        else{
            return temp*x;
        }
    }
};