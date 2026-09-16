class Solution {
private:
    int count(int n) {
        int r = 0;
        while (n) {
            n = n & (n - 1);
            r++;
        }
        return r;
    }
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);
        for (int i = 0; i <= n; i++) {
            result[i] = count(i);
        }
        return result;
    }
};
