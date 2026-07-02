class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zero_count = 0;

        for (int num: nums) {
            if (num != 0) {
                product = product * num;
            } else {
                zero_count++;
            }
        }

        if (zero_count > 1) {
            return vector<int>(nums.size(),0);
        }

        vector<int>result(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (zero_count > 0) {
                result[i] = (nums[i] == 0) ? product : 0;
            } else {
                result[i] = product / nums[i];
            }
        }
        return result;
    }
};
