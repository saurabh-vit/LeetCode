class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0; // Not enough prices to calculate differences
        }
        int minPrice = prices[0]; // Track the minimum price seen so far
        int maxDiff = 0;          // Maximum difference
        for (int i = 1; i < n; i++) {
            maxDiff = std::max(maxDiff, prices[i] - minPrice); // Update max difference
            minPrice = std::min(minPrice, prices[i]);          // Update minimum price
        }
        return maxDiff;
    }
};