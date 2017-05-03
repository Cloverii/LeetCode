class Solution {
public:
    double myPow(double x, int n) {
        double base = x;
        if(n < 0) base = 1 / x; // no need for n = -n;
        x = 1.0;
        while(n != 0) {
            if(n % 2)
                x *= base;
            base *= base;
            n /= 2;
        }
        return x;
    }
};
