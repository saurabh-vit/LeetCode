class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int n = nums.size();
        // if(n<=2) return n;
        // int count = 1;
        // for(int i = 1; i<n;){
        //     if(nums[i]==nums[i-1]){
        //         count++;
        //         if(count>2){
        //             nums.erase(nums.begin()+i);
        //             n--;
        //             continue;
        //         }
        //     }else{
        //         count = 1;
        //     }
        //     i++;
        // }
        // return n;

        int n = nums.size();
        if(n<=2) return n;
        int i = 2;
        for(int j = 2; j<n;){
            if(nums[j]==nums[j-i]){
                nums.erase(nums.begin()+j);
                n--;
            }else{
                j++;
            }
        }
        return n;
    }
};