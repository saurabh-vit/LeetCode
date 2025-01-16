class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        for(int i = 1; i<n;){
            if(nums[i]==nums[i-1]){
                count++;
                if(count>2){
                    nums.erase(nums.begin()+i);
                    n--;
                    continue;
                }
            }else{
                count = 1;
            }
            i++;
        }
        return n;
    }
};