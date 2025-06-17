class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    static constexpr int MAX = 1e5 + 10;

    vector<long long> fact, invFact;

    Solution() {
        fact.resize(MAX);
        invFact.resize(MAX);
        precompute();
    }

    long long pow_mod(long long a, long long b) {
        long long res = 1;
        a %= MOD;
        while (b > 0) {
            if (b % 2) res = res * a % MOD;
            a = a * a % MOD;
            b /= 2;
        }
        return res;
    }

    void precompute() {
        fact[0] = 1;
        for (int i = 1; i < MAX; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[MAX - 1] = pow_mod(fact[MAX - 1], MOD - 2);
        for (int i = MAX - 2; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        long long c = comb(n - 1, k);
        long long powPart = pow_mod(m - 1, n - k - 1);
        long long result = c * m % MOD * powPart % MOD;
        return result;
    }
};