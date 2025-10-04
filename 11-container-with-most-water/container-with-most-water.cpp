class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int contain = -1, maxC = 0;
        int i = 0, j = n-1;
        while(i < j){
            int contain = min(height[i], height[j]) * (j - i);
            maxC = max(contain, maxC);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxC;
    }
};