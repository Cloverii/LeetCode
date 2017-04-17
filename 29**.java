public class Solution {
    public static int divide(int dividend, int divisor) {
        if(dividend == Integer.MIN_VALUE && divisor == -1) 
            return Integer.MAX_VALUE;
        int ans = 0, base = 1;
        boolean flag = (dividend < 0) ^ (divisor < 0);
        long dividend1 = Math.abs((long)dividend); // explicitly convert
        long divisor1 = Math.abs((long)divisor); // explicitly convert
        while(dividend1 >= (divisor1 << 1)) {
            divisor1 <<= 1;
            base <<= 1;
        }
        while(divisor1 >= Math.abs((long)divisor)) { // explicitly convert
            if(dividend1 >= divisor1) {
                dividend1 -= divisor1;
                ans += base;
            }
            divisor1 >>= 1;
            base >>= 1;
        }
        return flag ? -ans : ans;
    }
}
