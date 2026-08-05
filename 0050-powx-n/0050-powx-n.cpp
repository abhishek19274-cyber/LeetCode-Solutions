class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        double result = 1.0;
        if(n<0)nn*=(-1);
        while(nn){
            if(nn%2){
                result = result*x;
                nn= nn - 1;
            }
            else{
                x =x*x;
                nn = nn/2;
            }
        }
        if(n<0)result = (double)(1.0)/(double)(result);
        return result;
    }
};