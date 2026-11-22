class Solution {
public:
    int m;
    int n;
    int orangesRotting(vector<vector<int>>& grid) {

        int ret = 0;

        int directions[4][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}};

        m = grid.size();
        n = grid[0].size();

        std::queue<std::pair<int,int>> q;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] != 2) continue;
                q.push({r,c});
            }
        }


        while (!q.empty()) {
            int size = q.size();
            bool rott = false;
            for (int i = 0; i < size; i++) {
                auto [r,c] = q.front();
                q.pop();


                for (auto& direc : directions) {
                    int nr = r+direc[0];
                    int nc = c+direc[1];

                    if (nr >= m or nc >= n or nr < 0 or nc < 0 or grid[nr][nc] != 1) continue;

                    if (grid[nr][nc] == 1) {
                        q.push({nr,nc});
                        grid[nr][nc] = 2;
                        rott = true;
                    }
                }
            }
            if (rott) ret ++;
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c]==1) return -1;
            }
        }
        return ret;
    }
};
