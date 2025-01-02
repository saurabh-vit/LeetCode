class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int st = 0, end = n-1;
        while(st<m && end>=0){
            if(target == matrix[st][end]){
                return true;
            }else if(target<matrix[st][end]){
                end--;
            }else {
                st++;
            }
        }
        return false;
    }
};