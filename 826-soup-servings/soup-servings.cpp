class Solution {
public:
    double soupServings(int n) {
        if (n >= 5000) return 1.0; 
        int m = (n + 24) / 25; 
        vector<vector<double>> dp(m + 1, vector<double>(m + 1, -1.0));
        function<double(int,int)> dfs = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5; 
            if (a <= 0) return 1.0;            
            if (b <= 0) return 0.0;            
            if (dp[a][b] != -1.0) return dp[a][b];
            dp[a][b] = 0.25 * (
                dfs(a - 4, b) +
                dfs(a - 3, b - 1) +
                dfs(a - 2, b - 2) +
                dfs(a - 1, b - 3)
            );
            return dp[a][b];
        };
        return dfs(m, m);
    }
};