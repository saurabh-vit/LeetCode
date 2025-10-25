class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int st = 1, count = 0;
        while(count<n){
            for(int i = 0; i<7 && count<n; i++){
                sum += st + i;
                count++;
            }
            st++;
        }
        return sum;
    }
};