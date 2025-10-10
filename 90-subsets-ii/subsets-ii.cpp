class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &curr, int i) {
        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }
        // Include nums[i]
        curr.push_back(nums[i]);
        helper(nums, ans, curr, i + 1);

        // Exclude nums[i]
        curr.pop_back();
        int idx = i+1;
        while(idx<nums.size() && nums[i]==nums[idx]){
            idx++;
        }
        helper(nums, ans, curr, idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, ans, curr, 0);
        return ans;
    }
};