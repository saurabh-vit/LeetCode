class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // unordered_set<int> s;
        // int n = nums.size();
        // for (int i = 0; i < n; i++)
        // {
        //     if(s.find(nums[i])!=s.end()){
        //         return nums[i];
        //     }
        //     s.insert(nums[i]);
        // }
        // return -1;

        //another approach
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(nums[i]==nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
};