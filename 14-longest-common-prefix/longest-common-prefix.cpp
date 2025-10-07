class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];

        // Step 1: Find common prefix between first and second strings
        string ans = "";
        string s1 = strs[0], s2 = strs[1];
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            if (s1[i] == s2[i])
                ans += s1[i];
            else
                break;
        }

        // Step 2: Compare ans with remaining strings
        for (int i = 2; i < strs.size(); i++) {
            string curr = strs[i];
            int j = 0;
            while (j < ans.size() && j < curr.size() && ans[j] == curr[j]) {
                j++;
            }
            ans = ans.substr(0, j); // shrink ans
            if (ans.empty()) return ""; // early exit if no common prefix
        }

        return ans;
    }

};