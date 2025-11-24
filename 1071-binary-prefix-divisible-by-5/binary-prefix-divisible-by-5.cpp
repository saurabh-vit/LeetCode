class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int n = 0;
        for(auto i : nums){
            n=((n*2)+i)%10;
            ans.push_back(n%5==0?true:false);
        }
        return ans;
    }
};