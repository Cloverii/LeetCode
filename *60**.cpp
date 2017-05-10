class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> v;
        int a[n + 1] = {1};
        for(int i = 1; i <= n; i++) {
            v.push_back(i);
            a[i] = a[i - 1] * i;
        }
        cout << a[1];
        k--;
        do {
            int tmp = k / a[n - 1];
            ans.push_back(v[tmp] + '0');
            v.erase(v.begin() + tmp);
            k %= a[n - 1];
        } while(--n);
        return ans;
    }
};
