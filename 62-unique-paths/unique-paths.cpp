class Solution {
public:
    // int ways(int m, int n, int r, int c){
    //     if(r == m-1 && c == n-1){
    //         return 1;
    //     }
    //     if(r>=m || c>=n){
    //         return 0;
    //     }
    //     int val1 = ways(m, n, r, c+1);
    //     int val2 = ways(m, n, r+1, c);
    //     return val1 + val2;
    // }
    // int uniquePaths(int m, int n) {
    //     return ways(m, n, 0, 0);
    // }

    int uniquePaths(int m, int n){
        long long ans = 1;
        int N = m + n - 2;
        int R = m - 1;
        for(int i = 1; i <= R; i++) {
            ans = ans * (N - R + i) / i;
        }
        return (int)ans;
    }
};