class Solution {
public:
    bool isPalindrome(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    string toBaseK(long long num, int k) {
        string res = "";
        while (num > 0) {
            res = char('0' + num % k) + res;
            num /= k;
        }
        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;

        // Generate palindromes in base-10
        for (int len = 1; count < n; len++) {
            // Generate half part and mirror it
            int halfStart = pow(10, (len - 1) / 2);
            int halfEnd = pow(10, (len + 1) / 2);

            for (int half = halfStart; half < halfEnd && count < n; ++half) {
                string halfStr = to_string(half);
                string fullStr = halfStr;

                if (len % 2 == 1) fullStr.pop_back(); // remove middle digit for odd length
                reverse(halfStr.begin(), halfStr.end());
                fullStr += halfStr;

                long long num = stoll(fullStr);
                string baseK = toBaseK(num, k);

                if (isPalindrome(baseK)) {
                    sum += num;
                    count++;
                }
            }
        }

        return sum;
    }
};