class Solution {
public:
    vector<int> nge(vector<int> &heights){
        int n = heights.size();
        stack<int> s;
        vector<int> ans(n, n);
        for(int i = n-1; i>=0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }

    vector<int> fge(vector<int> &heights){
        int n = heights.size();
        stack<int> s;
        vector<int> ans(n, -1);
        for(int i = 0; i<n; i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = fge(heights);
        vector<int> right = nge(heights);
        int maxarea = 0;
        for(int i = 0; i<n ;i++){
            int width = right[i]-left[i]-1;
            int area = width*heights[i];
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};