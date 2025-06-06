class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            if (i > farthest) return false;  // can't reach this index
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1) return true; // can reach or pass last index
        }
        return false;
    }
};