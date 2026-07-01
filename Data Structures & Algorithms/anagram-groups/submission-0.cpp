class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapp;
        
        for (string& s: strs) {
            vector<int> count(26,0);

            for (char c: s) {
                count[c - 'a']++;
            }

            string key;
            for (int x: count) {
                key += "#" + to_string(x);
            }

            mapp[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& [_,group]: mapp) {
            result.push_back(move(group));
        }
        return result;
    }
};
