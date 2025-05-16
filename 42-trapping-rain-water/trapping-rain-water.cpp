class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2) return 0;

        vector<int> left(n), right(n);
        left[0] = height[0];
        right[n-1] = height[n-1];

        for(int i = 1; i<n; i++){
            left[i] = max(left[i-1], height[i]);
        }

        for(int i = n-2; i>=0; i--){
            right[i] = max(right[i+1], height[i]);
        }

        int water = 0;
        for(int i = 0; i<n; i++){
            int current = min(left[i], right[i]) - height[i];
            if(current>0){
                water += current; 
            }
        }
        return water;
    }
};