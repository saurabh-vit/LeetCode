class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int st = 0;
        int count = 0;
        while(count<2*n){
            ans.push_back(nums[st]);
            st++;
            count++;
            if(st==n){
                st=0;
            }
        }
        return ans;
    }
};