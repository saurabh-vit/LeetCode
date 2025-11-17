class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        long long count = INT_MAX;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                count++;
            }else{
                if(count<k){
                    return false;
                }
                count = 0;
            }
        }
        return true;
    }
};