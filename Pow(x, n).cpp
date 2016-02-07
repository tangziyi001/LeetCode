// The parameter should be a double type
// Pay attention to 0,-1 and 1 case.
// Divide and Conquer to save time. Check if n is odd or even.
class Solution {
public:
    double hpow(double x, int n){
        if(n == 1) return x;
        if(n == -1) return 1/x;
        if(n%2 == 0){
            double now = hpow(x,n/2);
            return now*now;
        }
        else{
            return x*hpow(x,n-1);
        }
    }
    double myPow(double x, int n) {
        if(n == 0) return 1;
        return hpow(x,n);
    }
};