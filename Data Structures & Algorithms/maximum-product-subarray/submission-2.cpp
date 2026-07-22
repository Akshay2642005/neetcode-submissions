class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int current_max = 1;
        int current_min = 1;
        int ans = INT_MIN;
        for (auto& num: nums) {
            if (num < 0) swap(current_max, current_min);
            current_max = max(num, current_max * num);
            current_min = min(num, current_min * num);
            ans = max(ans, current_max);
        }
        return ans;
    }
};
