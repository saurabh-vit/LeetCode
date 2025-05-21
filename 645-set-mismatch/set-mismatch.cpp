class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dublicate = -1, missing = -1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n-1; i++){
            if(nums[i]==nums[i+1]){
                dublicate = nums[i];    // 2
            }
        }
        int expected = n * (n + 1) / 2;     // 10
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];             // 9
        }
        missing = expected - (sum-dublicate);       // 10 - (9-2)
        return {dublicate, missing};
    }
};