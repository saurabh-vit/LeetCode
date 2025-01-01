class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<m; j++){
        //         if(matrix[i][j]==target){
        //             return true;
        //         }
        //     }
        // }

        //another approach
        int i = 0, j = 0, end = m-1, st = 0;
        while(i<n){
            if(matrix[i][m-1] < target){
                i++;
            }else {
                int st = 0, end = m-1;
                while(st <= end){
                    int mid = st+(end-st)/2;
                    if(matrix[i][mid] == target){
                        return true;
                    }else if(matrix[i][mid] < target){
                        st++;
                    }else{
                        end--;
                    }
                }
                return false;
            }
        }

        return false;
    }
};