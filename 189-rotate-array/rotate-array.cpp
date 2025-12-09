class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<=1){
            return;
        }
        vector<int> ans;
        k=k%n;
        while(k>0){
            if(k>0){
                ans.push_back(nums[n-k]);
                k--;
            }
        }
        for(int i = k; i<n; i++){
            if(ans.size()==n){
                break;
            }else{
                ans.push_back(nums[i+k]);
            }
        }
        nums = ans;
    }
};