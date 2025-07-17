class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;

        // dp[i]: map of mod_value -> maximum subsequence length ending at i with that mod_value
        vector<unordered_map<int,int>> dp(n);

        for(int i = 0; i < n; i++) {
            dp[i][0] = 1; // Single element subsequence

            for(int j = 0; j < i; j++) {
                int mod_val = (nums[j] + nums[i]) % k;

                // Extend the subsequence from j to i with the same mod_val
                int len = 2;
                if(dp[j].count(mod_val)){
                    len = dp[j][mod_val] + 1;
                }

                dp[i][mod_val] = max(dp[i][mod_val], len);
                ans = max(ans, dp[i][mod_val]);
            }
        }

        return ans;
    }
};