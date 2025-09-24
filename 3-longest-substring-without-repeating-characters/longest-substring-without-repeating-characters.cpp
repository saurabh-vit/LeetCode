class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int st = 0;
        vector<int> last(256, -1);
        for(int i = 0; i<n; i++){
            if(last[s[i]]>=st){
                st = last[s[i]]+1;
            }
            last[s[i]] = i;
            ans = max(ans, i - st+1);
        }
        return ans;
    }
};