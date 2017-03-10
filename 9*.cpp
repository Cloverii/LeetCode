class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0;
        int len = 1, xx = x;
        while(xx / 10) {
            xx /= 10;
            len++;
        }
        xx = x;
        int base = 1;
        for(int i = 0; i < len - 1; i++) 
            base *= 10;
        for(int i = 1; i * 2 <= len; i++) {
            int tmp1 = xx % 10, tmp2 = xx / base;
            if(tmp1 != tmp2) return 0;
            xx -= tmp2 * base; xx /= 10;
            base /= 100;
        }
        return 1;
    }
};
