class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        vector<int> sizes;
        string result;
        for (string& s: strs) {
            sizes.push_back(s.size());
        }
        for (int size: sizes) {
            result += to_string(size);
            result.push_back(',');
        }

        result.push_back('#');
        for (string& s: strs) {
            result.append(s);
        }

        return result;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<int> sizes;
        vector<string> result;

        int i = 0;
        while(s[i] != '#') {
            int j = i;
            while (s[j] != ',') j++;
            sizes.push_back(stoi(s.substr(i, j-i)));
            i = j + 1;
        }
        i++;

        for (int size: sizes) {
            result.push_back(s.substr(i, size));
            i += size;
        }
        return result;
    }
};
