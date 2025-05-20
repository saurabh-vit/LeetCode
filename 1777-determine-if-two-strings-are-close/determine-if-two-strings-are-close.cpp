class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n!=m){
            return false;
        }
        vector<int> freq1(26, 0), freq2(26, 0);
        unordered_set<char> set1, set2;
        for (char c : word1) {
            freq1[c - 'a']++;
            set1.insert(c);
        }

        for (char c : word2) {
            freq2[c - 'a']++;
            set2.insert(c);
        }

        if (set1 != set2) return false;

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};