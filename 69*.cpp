class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x + 1LL;
        while(l < r) {
            int m = (r - l) / 2 + l;
            if(x >= 1LL * m * m) l = m + 1;
            else r = m;
        }
        return l - 1;
    }
};
