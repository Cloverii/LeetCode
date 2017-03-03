class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        int xx = x, len = 0;
        while(xx != 0) {
            len++;
            xx /= 10;
        }
        //cout << "len" << len << endl;
        int base = 1;
        for(int i = 0; i < len - 1; i++) {
            base *= 10;
        }
        while(x != 0) {
            int tmp = x % 10;
            ans += 1LL * tmp * base;
            //cout << 1LL * tmp * base<< ' ' << ' ' << tmp << ' ' << base << endl;
            base /= 10;
            x /= 10;
        }
        if(ans > INT_MAX || ans < INT_MIN) return 0;
        return ans;
    }
};
