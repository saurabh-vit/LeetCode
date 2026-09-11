class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>freq;
        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
        }
        int ans = 0;
        int maxfreq = 0;
        for(auto it : freq){
            if(it.second>maxfreq){
                maxfreq = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};