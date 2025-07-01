class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0) return "";
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            int st = i, end = i;
            while (st >= 0 && end < n && s[st] == s[end]) {
                if (end - st > r - l) {
                    l = st;
                    r = end;
                }
                st--;
                end++;
            }
            st = i;
            end = i + 1;
            while (st >= 0 && end < n && s[st] == s[end]) {
                if (end - st > r - l) {
                    l = st;
                    r = end;
                }
                st--;
                end++;
            }
        }
        return s.substr(l, r - l + 1);
    }
};