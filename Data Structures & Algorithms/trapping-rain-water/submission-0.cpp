class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int l = 0, r = height.size() - 1;
        int max_left = height[l] , max_right = height[r];
        int result = 0;
        while (l < r) {
            if (max_left < max_right) {
                l++;
                max_left = max(max_left, height[l]);
                result += max_left - height[l];
            } else {
                r--;
                max_right = max(max_right, height[r]);
                result += max_right - height[r];
            }
        }
        return result;
    }
};
