class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2){
            return 0;
        }
        int maxprice = 0;
        int minprice = prices[0];
        for(int i = 1; i<n; i++){
            maxprice = max(maxprice, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }
        return maxprice;
    }
};