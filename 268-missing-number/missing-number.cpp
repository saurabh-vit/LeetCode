class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[0] != 0) return 0;
        if (nums[n - 1] != n) return n;
        // int ans = -1;
        for(int i = 0; i<n-1; i++){
            if(nums[i]+1!=nums[i+1]){
                return nums[i]+1;
            }
        }
        return n;
    }
};