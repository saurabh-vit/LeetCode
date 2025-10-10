class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, int i, vector<int> &curr){
        if(i==nums.size()){
            ans.push_back({curr});
            return;
        }
        curr.push_back(nums[i]);
        helper(nums, ans, i+1, curr);
        curr.pop_back();
        helper(nums, ans, i+1, curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, ans, 0, curr);
        return ans;
    }
};