class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char c : s) {
            if (isalnum(c)) {
                str += tolower(c);
            }
        }
        int n = str.length();
        int st = 0, end = n-1;
        while(st<end){
            if(str[st]!=str[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};