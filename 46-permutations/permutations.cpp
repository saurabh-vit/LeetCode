class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> &curr, vector<bool> &check){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(check[i]) continue;
            check[i] = true;
            curr.push_back(nums[i]);
            helper(nums, ans, curr, check);
            curr.pop_back();
            check[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> check(nums.size(), false);
        helper(nums, ans, curr, check);
        return ans;
    }
};