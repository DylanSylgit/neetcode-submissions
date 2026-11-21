#include <utility>

class Solution {
public:
    int rows;
    int cols;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        std::queue<std::pair<int,int>> coords;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != 0) {
                    continue;
                }
                coords.push({r,c});
            }
        }

        int dirs[4][2] = {{1,0}, {0,1} , {-1,0}, {0,-1}};

        while (!coords.empty()) {
            auto [r,c] = coords.front();
            coords.pop();

            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= rows or nc >= cols or nr < 0 or nc < 0 or grid[nr][nc] != 2147483647) {
                    continue;
                }
                grid[nr][nc] = grid[r][c] + 1;
                coords.push({nr,nc});
            }
        }


    }

};
