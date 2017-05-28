class Solution {
private:
    int findKthElement(vector<int>& nums1, vector<int>& nums2, int l, int r, int k) {
        while(l < r) {
            int m = l + (r - l) / 2;
            int cnt = upper_bound(nums1.begin(), nums1.end(), m) - nums1.begin() + 
                upper_bound(nums2.begin(), nums2.end(), m) - nums2.begin();
            if(cnt <= k) l = m + 1;
            else r = m;
        }
        return l;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int minn = INT_MAX, maxx = INT_MIN;
        if(nums1.size()) { minn = min(nums1[0], minn), maxx = max(nums1[nums1.size() - 1], maxx); }
        if(nums2.size()) { minn = min(nums2[0], minn), maxx = max(nums2[nums2.size() - 1], maxx); }
        int n = nums1.size() + nums2.size();
        if(n & 1) {
            return findKthElement(nums1, nums2, minn, maxx, n / 2); 
        } else {
            return (findKthElement(nums1, nums2, minn, maxx, n / 2) + 
                findKthElement(nums1, nums2, minn, maxx, n / 2 - 1)) / 2.0;
        }
    }
};
