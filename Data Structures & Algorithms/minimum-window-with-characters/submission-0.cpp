class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        unordered_map<char, int> T, window;
        for (char c: t) T[c]++;

        int have = 0, need = T.size(), l = 0, resLen = INT_MAX;
        pair<int, int> res = {-1, 1};

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;
            if (T.count(c) && window[c] == T[c]) {
                have++;
            }
            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l,r};
                }
                window[s[l]]--;
                if (T.count(s[l]) && window[s[l]] < T[s[l]]) have--;
                l++;
            }
        }
        return resLen == INT_MAX ? "": s.substr(res.first, resLen);
    }
};
