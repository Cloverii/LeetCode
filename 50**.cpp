class Solution {
public:
    double myPow(double x, int n) {
        double base = x;
        if(n < 0) base = 1 / x;
        x = 1.0;
        long long nn = abs(n * 1LL);
        while(nn != 0) {
            if(nn & 1) {
                x *= base;
            }
            base *= base;
            nn >>= 1;
        }
        return x;
    }
};
