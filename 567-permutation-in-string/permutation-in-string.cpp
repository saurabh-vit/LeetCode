class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        std::vector<int> s1Freq(26, 0), windowFreq(26, 0);
        for (char c : s1) {
            s1Freq[c - 'a']++;
        }
        int n = s1.length();
        for (int i = 0; i < n; ++i) {
            windowFreq[s2[i] - 'a']++;
        }
        if (s1Freq == windowFreq) return true;
        for (int i = n; i < s2.length(); ++i) {
            windowFreq[s2[i] - 'a']++;
            windowFreq[s2[i - n] - 'a']--;
            if (s1Freq == windowFreq) return true;
        }
        return false;
    }
};