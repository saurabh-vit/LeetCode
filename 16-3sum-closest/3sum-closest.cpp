class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            int st = i + 1, end = n - 1;
            while (st < end) {
                int sum = nums[i] + nums[st] + nums[end];
                if (abs(sum-target)<abs(closestSum-target)) {
                    closestSum = sum;
                }
                if (sum < target) {
                    st++;
                } else if (sum > target) {
                    end--;
                } else {
                    return sum;
                }
            }
        }
        return closestSum;
    }
};