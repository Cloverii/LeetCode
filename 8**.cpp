class Solution {
public:
    int myAtoi(string str) {
        if(!str.size()) return 0;
        int ans = 0, flag = 1, i = 0;
        while(i < str.size() && isblank(str[i])) i++; 
        if(str[i] == '-' || str[i] == '+')
            flag -= (str[i++] == '-') * 2;
        for( ; i < str.size() && isdigit(str[i]); i++) {
            if(ans > INT_MAX / 10 || ans == INT_MAX / 10 && str[i] > '7') //if INT_MIN, return INT_MIN; if INT_MAX, continue calculating;
                return flag == 1 ? INT_MAX : INT_MIN;
            ans = ans * 10 + (str[i] - '0');
        }
        return ans * flag;
    }
};
