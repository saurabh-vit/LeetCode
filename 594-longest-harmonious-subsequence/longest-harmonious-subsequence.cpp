class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        
        int longest = 0;
        for(auto it : freq){
            if(freq.find(it.first + 1) != freq.end()){
                longest = max(longest, it.second + freq[it.first + 1]);
            }
        }
        return longest;
    }
};