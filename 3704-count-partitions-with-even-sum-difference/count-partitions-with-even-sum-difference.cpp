class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        int c1 = 0, c2 = 0;
        for(int i = 0; i<n-1; i++){
            c1 += nums[i];
            c2 = sum - c1;
            if((c1-c2)%2 == 0){
                count++;
            }
        }
        return count;
    }
};