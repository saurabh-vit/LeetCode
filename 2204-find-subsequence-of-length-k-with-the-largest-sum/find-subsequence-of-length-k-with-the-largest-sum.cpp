class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        multiset<int> s;
        for(auto num : nums){
            s.insert(num);
            if(s.size() > k){
                s.erase(s.begin());
            }
        }

        vector<int> ans;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i]) != s.end() && count < k){
                ans.push_back(nums[i]);
                s.erase(s.find(nums[i]));
                count++;
            }
        }
        return ans;
    }
};