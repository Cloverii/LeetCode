class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int carry = 0, res = 0;
        int i = 0;
        while(i < a.size() || i < b.size()) {
            res = carry;
            if(i < a.size()) res += a[i] - '0';
            if(i < b.size()) res += b[i] - '0';
            ans.push_back((res & 1) + '0');
            carry = res >> 1;
            ++i;
        }
        if(carry)
            ans.push_back(carry + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
