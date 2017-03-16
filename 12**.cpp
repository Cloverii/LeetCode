class Solution {
public:
    map<int, char> mp = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
    string ans;
    
    string intToRoman(int num) {
        transfer(num, 1);
        return ans;
    }
    void transfer(int num, int base) { 
            if(num == 0) return;
            transfer(num / 10, base * 10); // to reverse
            int tmp = num % 10;
            if(tmp > 5 && tmp < 9) ans += mp[5 * base];
            if(tmp % 5 == 4) ans += mp[1 * base];
            if(tmp % 5 < 4) 
                for(int i = 0; i < tmp % 5; i++)
                    ans += mp[1 * base];
            if(tmp == 5 || tmp == 4) ans += mp[5 * base];
            if(tmp == 9) ans += mp[10 * base];
            num /= 10, base *= 10;        
    }
};
