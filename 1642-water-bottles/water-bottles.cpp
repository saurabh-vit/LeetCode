class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        while(empty>=numExchange){
            int newbottle = empty/numExchange;
            ans += newbottle;
            empty = newbottle + (empty % numExchange);
        }
        return ans;
    }
};