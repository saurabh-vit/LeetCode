class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            int st = i+1, end = n-1;
            while(st<end){
                int sum = nums[i]+nums[st]+nums[end];
                ans.push_back(sum);
                if(sum < target){
                    st++;
                }else if(sum>target){
                    end--;
                }else{
                    return sum;
                }
            }
        }
        vector<int> right;
        for(int i = 0; i<ans.size(); i++){
            right.push_back(std::abs(ans[i]-target));
        }
        int mindiff = *std::min_element(right.begin(), right.end());
        for (int i = 0; i < ans.size(); i++) {
            if (std::abs(ans[i] - target) == mindiff) {
                return ans[i];
            }
        }
        return 0;
    }
};