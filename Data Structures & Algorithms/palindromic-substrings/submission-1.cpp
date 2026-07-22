class Solution {
   private:
    int helper(string s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
        return count;
    };

   public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += helper(s, i, i);
            res += helper(s, i, i + 1);
        }
        return res;
    }
};
