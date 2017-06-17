class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!nums2.size()) return;
        int cur = --m + --n + 1;
        while(n >= 0 && m >= 0) {
            nums1[cur--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
        while(n >= 0) {
            nums1[cur--] = nums2[n--];
        }
    }
};
