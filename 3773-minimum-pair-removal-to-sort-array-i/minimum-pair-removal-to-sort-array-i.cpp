class Solution {
    bool isSorted(vector<int> &nums){
        int n = nums.size();
        int minSum = INT_MAX, ind = 0;
        bool flag = true;
        for(int i = 1; i < n; i++){
            if(nums[i - 1] > nums[i]){
                flag = false;
            }
            if(nums[i - 1] + nums[i] < minSum){
                minSum = nums[i - 1] + nums[i];
                ind = i - 1;
            }
        }
        if(flag == true){
            return true;
        }
        nums.erase(nums.begin() + ind);
        nums[ind] = minSum;
        return false;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(isSorted(nums) == false){
            ops++;
        }
        return ops;
    }
};