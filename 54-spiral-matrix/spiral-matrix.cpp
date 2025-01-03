class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int rs = 0, cs = 0, re = m-1, ce = n-1;
        vector<int> result; 
        while(rs<=re && cs<=ce){
            for(int i = cs; i<=ce; i++){
                result.push_back(matrix[rs][i]);
            }
            rs++;
            for(int i = rs; i<=re; i++){
                result.push_back(matrix[i][ce]);
            }
            ce--;
            if (rs <= re) {
                for(int i = ce; i>=cs; i--){
                    result.push_back(matrix[re][i]);
                }
            }
            re--;
            if (cs <= ce) {
                for(int i = re; i>=rs; i--){
                    result.push_back(matrix[i][cs]);
                }
            }
            cs++;
        }
        return result;
    }
};