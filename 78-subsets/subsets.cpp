class Solution {
public:
    void set(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allset){
        if(i == nums.size()){
            allset.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        set(nums, ans, i+1, allset);

        ans.pop_back();
        set(nums, ans, i+1, allset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allset;
        vector<int> ans;
        set(nums, ans, 0, allset);
        return allset;
    }
};