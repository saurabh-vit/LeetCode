class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        int mod = 1e9 + 7;
        int bitLength = 0;

        for (int i = 1; i <= n; ++i) {
            // If i is a power of 2, the number of bits required increases by 1
            // e.g., 1 (1), 2 (10), 4 (100), 8 (1000)
            if ((i & (i - 1)) == 0) {
                bitLength++;
            }
            
            // 1. Shift current answer to the left by the bit length of i
            // 2. Add i to the answer
            // 3. Apply modulo
            ans = ((ans << bitLength) + i) % mod;
        }

        return (int)ans;
    }
};