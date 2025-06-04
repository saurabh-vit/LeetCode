class Solution {
public:
    int find(vector<int>& nums, int st, int end){
        if(st == end) return nums[st];

        int mid = st + (end - st) / 2;

        if ((mid == 0 || nums[mid] < nums[mid - 1]) &&
            (mid == nums.size() - 1 || nums[mid] < nums[mid + 1])) {
            return nums[mid];
        }

        // search right half if left is sorted and pivot is on right
        if (nums[mid] >= nums[st] && nums[end] < nums[mid]) {
            return find(nums, mid + 1, end);
        } else {
            return find(nums, st, mid);
        }
    }

    int findMin(vector<int>& nums) {
        return find(nums, 0, nums.size() - 1);
    }
};
