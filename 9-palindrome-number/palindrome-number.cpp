class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        std::string str = std::to_string(x);
        std::string reversed_str = str;
        std::reverse(reversed_str.begin(), reversed_str.end());
        return str == reversed_str;
    }
};