class Solution {
public:
    void set(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &finalset){
        if(i == nums.size()){
            finalset.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        set(nums, ans, i+1, finalset);
        ans.pop_back();
         while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        set(nums, ans, i+1, finalset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> finalset;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        set(nums, ans, 0, finalset);
        return finalset;
    }
};