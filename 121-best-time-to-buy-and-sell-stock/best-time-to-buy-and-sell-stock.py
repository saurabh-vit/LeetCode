class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        maxp = 0
        minp = prices[0]
        for i in range(n):
            maxp = max(maxp, prices[i]-minp)
            minp = min(minp, prices[i])
        return maxp