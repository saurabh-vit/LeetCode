class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        vector<vector<int>>row(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>>col(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>>dl(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>>dr(grid.size(),vector<int>(grid[0].size(),0));
        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                row[i][j] += grid[i][j];
                col[i][j] += grid[i][j];
                dl[i][j] += grid[i][j];
                dr[i][j] += grid[i][j];
                if(j!=0)row[i][j] += row[i][j-1];
                if(i!=0)col[i][j] += col[i-1][j];
                if(i>0 && j>0) dl[i][j] += dl[i-1][j-1];
                if(i>0 && j<(grid[0].size()-1)) dr[i][j] += dr[i-1][j+1];
            }
        }
        int side = min(grid.size(),grid[0].size());
        for(int k = side ; k>1;k--){
            for(int i=0;i<=(grid.size()-k);i++){
                for(int j=0;j<=(grid[0].size()-k);j++){
                    bool check = true;
                    int tar = row[i][j+k-1];
                    if(j>0) tar -= row[i][j-1];
                    for(int r = (i+1) ; r<(i+k) ; r++){
                        int sum = row[r][j+k-1];
                        if(j>0) sum -= row[r][j-1];
                        if(sum != tar){
                            check = false;
                            break;
                        }
                    }
                    if(!check)continue;
                    for(int c=j;c<(j+k);c++){
                        int sum = col[i+k-1][c];
                        if(i>0) sum -= col[i-1][c];
                        if(sum!=tar){
                            check = false;
                            break;
                        }
                    }
                    int dlsum = dl[i+k-1][j+k-1];
                    if(i>0 && j>0) dlsum -= dl[i-1][j-1];
                    if(dlsum!=tar){
                        check = false;
                        continue;
                    }
                    int drsum = dr[i+k-1][j];
                    if(i>0 && (j+k-1)<(grid[0].size()-1)) drsum -= dr[i-1][j+k];
                    if(drsum!=tar){
                        check = false;
                    }
                    if(check==true){
                        return k;
                    }
                }
            }
        }
        return 1;
    }
};