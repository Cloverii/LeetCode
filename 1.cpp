#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#define PRLN(i) cout << #i << " = " << i << endl;
#define DEBUG cout << "bug" << endl
using namespace std;

class Solution {
    typedef pair<int, int> Pair;
    bool cmp (const Pair &x, const Pair &y) {
        return x.first < y.first || 
            x.first == y.first && x.second < y.second;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int arr[2];
        for(int i = 0; i < nums.size(); i++) {
            int tmp = target - nums[i];
            for(int j = i; j < nums.size(); j++) 
                if(tmp == nums[j]) {
                    arr[0] = i, arr[1] = j;
                    break;
                }
        }
        vector<int> ans(arr, arr + 2);
        return ans;
    }
};

int main(void) {
    freopen("in.txt", "r", stdin);
    int n;
    vector<int> v;
    while(cin >> n && n != -1) v.push_back(n);
    int t = v[v.size() - 1];
    v.pop_back();
    vector<int> ans;
    Solution s;
    ans = s.twoSum(v, t);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
