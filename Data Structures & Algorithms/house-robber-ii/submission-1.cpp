class Solution {
private:
    int helper(vector<int>& nums, int start, int end) {
        if (end - start <=1) return nums[start];
        int rob1 = nums[start];
        int rob2 = max(nums[start], nums[start + 1]);
        
        for (int i = start + 2; i <  end; i++) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int rob1 = helper(nums, 0, n-1);
        int rob2 = helper(nums, 1, n);

        return max(rob1, rob2);
    }
};
