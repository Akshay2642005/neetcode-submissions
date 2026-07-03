class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char,char> valid_sequence = {
            {')','('},
            {']','['},
            {'}','{'}
        };

        for (char c: s) {
            if (valid_sequence.count(c)) {
                if (!stack.empty() && stack.top() == valid_sequence[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
