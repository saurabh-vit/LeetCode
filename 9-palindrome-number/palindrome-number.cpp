class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string str = to_string(x);
        string str2 = str;
        reverse(str2.begin(), str2.end());
        if(str==str2){
            return true;
        }else{
            return false;
        }
    }
};