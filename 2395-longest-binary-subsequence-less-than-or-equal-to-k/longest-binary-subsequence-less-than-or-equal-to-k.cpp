class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int c = 0;
        long long value = 0;
        long long power = 1;
        for(int i = n-1; i>=0; i--){
            if(s[i]=='0'){
                c++;
            }else{
                if(power <= k-value){
                    value += power;
                    c++;
                }
            }
            if(power<=k){
                power *= 2;
            }
        }
        return c;
    }
};