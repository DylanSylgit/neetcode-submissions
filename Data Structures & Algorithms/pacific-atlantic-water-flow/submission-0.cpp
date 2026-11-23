class Solution {
public:
    int m;
    int n;
    int directions[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        std::vector<std::vector<bool>> pacific(m,std::vector<bool>(n,false));
        std::vector<std::vector<bool>> atlantic(m,std::vector<bool>(n,false));

        for (int c = 0; c < n; c++) {
            dfs(heights,pacific,0,c);
            dfs(heights,atlantic,m-1,c);
        }

        for (int r = 0; r < m; r++) {
            dfs(heights,pacific,r,0);
            dfs(heights,atlantic,r,n-1);
        }

        std::vector<std::vector<int>> ret;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (atlantic[r][c] and pacific[r][c]) {
                    ret.push_back({r,c});
                }
            }
        }
        return ret;
    }

    void dfs(std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (nr < 0 or nc < 0 or nr >= m or nc >= n) continue;
            if (visited[nr][nc]) continue;

            if (heights[nr][nc] < heights[r][c]) continue;

            dfs(heights,visited,nr,nc);
        }


    }
};
