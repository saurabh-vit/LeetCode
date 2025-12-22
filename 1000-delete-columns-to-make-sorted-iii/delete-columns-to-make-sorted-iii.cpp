class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows=strs.size();
        int cols=strs[0].size();
         vector<int>dp(cols,1);
         for (int j = 0; j < cols; j++) {
            for (int i = 0; i < j; i++) {
             bool ok=true;
            for(int row=0;row<rows;row++){
                if(strs[row][i]>strs[row][j]){
                    ok=false;
                    break;
                }
            }
            if(ok){
             dp[j]=max(dp[j],dp[i]+1);
                continue;
            }
            } 
        }
      int maxKeep = *max_element(dp.begin(), dp.end());
        return cols - maxKeep;
    }
};