class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long overall = 0;
        for(int i=0; i<n; i++)
        {
            overall += prices[i]*strategy[i];
        }
        long long maxi = overall;
        for(int i=0; i<k/2; i++)
        {
            overall -= prices[i]*strategy[i];
        }
        for(int i=k/2; i<k; i++)
        {
            overall += prices[i]*(1-strategy[i]);
        }
        maxi = max(maxi,overall);
        for(int i=1; i<=n-k; i++)
        {
            overall += (long long)prices[i-1]*strategy[i-1]-(long long)prices[i-1+k/2]+(long long)prices[i-1+k]*(1-strategy[i-1+k]);
            maxi = max(maxi,overall);
        }
        return maxi;
    }
};