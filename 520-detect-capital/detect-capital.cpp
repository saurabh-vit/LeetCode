class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;
        
        for(char c : word) {
            if(isupper(c)) capitalCount++;
        }
        
        // Case 1: All caps
        if(capitalCount == word.size()) return true;
        
        // Case 2: All small
        if(capitalCount == 0) return true;
        
        // Case 3: Only first capital
        if(capitalCount == 1 && isupper(word[0])) return true;
        
        return false;
    }
};