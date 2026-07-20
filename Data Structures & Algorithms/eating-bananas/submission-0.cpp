class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int left = 1, right = *max_element(piles.begin(), piles.end());
      int result = right;
      while (left <= right) {
        int k = (left + right) / 2;
        long long total_time = 0;
        for (int p: piles) {
            total_time += ceil(static_cast<double>(p) / k);
        }
        if (total_time <= h) {
            result = k;
            right = k - 1;
        } else {
            left = k + 1;
        }
      }
      return result;
    }
};
