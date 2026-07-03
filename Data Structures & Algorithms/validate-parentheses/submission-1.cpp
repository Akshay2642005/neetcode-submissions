class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        stack.push(s[0]);
        for (int i = 1; i < s.length(); i++) {
            char top;
            if(stack.empty()) top = '.';
            else top = stack.top();
            if(s[i] == '[' || s[i] == '(' || s[i] == '{') stack.push(s[i]);
            else if ((top == '(' && s[i] == ')') 
            || (top == '[' && s[i] == ']' )
            || (top == '{' && s[i] == '}')
            ) stack.pop();
            else return false;
        }

        if(stack.empty()) return true;
        else return false;
    }
};
