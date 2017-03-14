class Solution {
public:
    int maxArea(vector<int>& height) { // two pointers
/*        int h[2];
        h[0] = 0, h[1] = height.size() - 1;
        int ans = min(h[0], h[1]) * (h[1] - h[0] + 1);
        while(h[0] < h[1]) {
            bool flag = height[h[0]] > height[h[1]];  //flag  = lowID;
            int step = 1 - 2 * flag, lowHeight = height[h[flag]];
            int &low = h[flag]; int &high = h[flag ^ 1];
            while(lowHeight >= low) h[flag] += step;
            int tmp = min(low, high) * (abs(h[flag ^ 1] - h[flag]) + 1);
            ans = max(tmp, ans);
            cout << h[0] << ' ' << h[1] << endl;
        }*/
        int l = 0, r = height.size() - 1;
        int ans = min(height[l], height[r]) * (r - l);
        while(l < r) {
            int minn = min(height[l], height[r]);
            if(height[l] > height[r])
                while(minn >= height[r]) r--;
            else 
                while(minn >= height[l]) l++;
            int tmp = min(height[l], height[r]) * (r - l);
            ans = max(ans, tmp);            
        }
        return ans;
    }
};
