class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(string s: strs) {
            string t = s;
            sort(s.begin(), s.end());
            mp[s].push_back(t);
        }
        for(auto v: mp) {
            ans.push_back(v.second);
        }
        return ans;
    }
};
