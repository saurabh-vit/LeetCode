class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(int i = 0; i<s.size(); i++){
            if(isalnum(s[i])){
                ans+=tolower(s[i]);
            }
        }
        int n = ans.size();
        int st = 0, end = n-1;
        while(st<end){
            if(ans[st]!=ans[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};