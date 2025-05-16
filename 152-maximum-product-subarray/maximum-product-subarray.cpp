class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int maxProduct = nums[0];
        int left = 1, right = 1;
        for(int i = 0; i<n; i++){
            // Multiply from the left
            if (left == 0) {
                left = 1;
            }
            left *= nums[i];

            // Multiply from the right
            if (right == 0) {
                right = 1;
            }
            right *= nums[n - 1 - i];
            maxProduct = max({maxProduct, left, right});
        }
        return maxProduct;
    }
};