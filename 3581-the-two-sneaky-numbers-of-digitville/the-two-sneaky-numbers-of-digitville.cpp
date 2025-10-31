class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> freq(nums.size()+1, 0);
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]]++;
            if(freq[nums[i]] == 2){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};