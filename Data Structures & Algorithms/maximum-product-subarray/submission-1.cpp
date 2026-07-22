class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int currentMin = 1;
        int currentMax = 1;
        for (int n: nums) {
            if (n == 0) {
                ans = max(ans, 0);
                currentMin = 1, currentMax = 1;
                continue;
            }
            int prevMax = currentMax;
            int prevMin = currentMin;
            currentMax = max({n, n * prevMax, n* prevMin});
            currentMin = min({n, n * prevMax, n* prevMin});
            ans = max({ans, currentMax, currentMin});
        }
        return ans;
    }
};
