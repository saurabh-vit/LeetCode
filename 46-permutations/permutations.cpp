class Solution {
public:
    void backtrack(vector<int>& nums, int st, vector<vector<int>>& result){
        if(st == nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i = st; i<nums.size(); i++){
            swap(nums[st], nums[i]);
            backtrack(nums, st+1, result);
            swap(nums[st], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};