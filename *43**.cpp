class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        int carry = 0;
        int l = num1.size() + num2.size() - 1;
        int a[l]; memset(a, 0, sizeof(a));
        for(int i = 0; i < num1.size(); i++) {
            for(int j = 0; j < num2.size(); j++) {
                a[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        while(--l >= 0) {
            a[l] += carry;
            carry = a[l] / 10;
            ans += a[l] % 10 + '0';
        }
        l = num1.size() + num2.size() - 1;
        if(carry) ans += carry + '0';
        reverse(ans.begin(), ans.end());
        if(count(ans.begin(), ans.end(), '0') == ans.size()) ans.resize(1);
        return ans;
    }
};
