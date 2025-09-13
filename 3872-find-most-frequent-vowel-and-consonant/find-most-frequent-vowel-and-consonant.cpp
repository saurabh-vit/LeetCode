class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        int maxVowel = 0, maxConsonant = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            char c = 'a' + i;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                maxVowel = max(maxVowel, freq[i]);
            } else {
                maxConsonant = max(maxConsonant, freq[i]);
            }
        }
        return maxVowel + maxConsonant;
    }
};