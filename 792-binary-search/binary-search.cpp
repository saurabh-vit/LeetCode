class Solution {
public:
    int binary(vector<int> &nums, int st, int end, int target){
        if(st<=end){
            int mid = st+(end-st)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                return binary(nums, mid+1, end, target);
            }else{
                return binary(nums, st, mid-1, target);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size()-1;
        return binary(nums, st, end, target);
    }
};