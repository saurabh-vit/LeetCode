class Solution {
public:
    bool isValid(string s) {
         std::stack<char> stack;
        std::unordered_map<char, char> matchingBrackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (char c : s) {
            if (matchingBrackets.count(c)) {
                if (stack.empty() || stack.top() != matchingBrackets[c]) {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};