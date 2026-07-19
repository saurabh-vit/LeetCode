class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxp = 0, minp = prices[0];
        for(int i = 0; i<n; i++){
            maxp = max(maxp, prices[i]-minp);
            minp = min(minp, prices[i]);
        }
        return maxp;
    }
};