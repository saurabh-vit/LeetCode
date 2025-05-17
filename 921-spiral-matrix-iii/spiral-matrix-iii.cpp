class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int total = rows * cols;
        int count = 0;

        int dirX[] = {0, 1, 0, -1};
        int dirY[] = {1, 0, -1, 0};

        int x = rStart, y = cStart;
        int steps = 1;

        result.push_back({x, y});
        count++;

        while (count < total) {
            for (int dir = 0; dir < 4; dir++) {
                int moveSteps = (dir % 2 == 0) ? steps : steps;
                for (int i = 0; i < moveSteps; i++) {
                    x += dirX[dir];
                    y += dirY[dir];

                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        result.push_back({x, y});
                        count++;
                        if (count == total) break;
                    }
                }
                if (dir % 2 == 1) steps++;
                if (count == total) break;
            }
        }

        return result;
    }
};