class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                if (grid[r][c] == 0) continue;
                int curr = 0;
                dfs(grid,r,c,curr,ret);
                ret = max(ret,curr);
            }
        }


        return ret;
        
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int& curr, int& ret) {
        if (r >= grid.size() or r < 0 or c >= grid[r].size() or c < 0 or grid[r][c] == 0) return;

        curr ++;
        grid[r][c] = 0;

        dfs(grid,r+1,c,curr,ret);
        dfs(grid,r-1,c,curr,ret);
        dfs(grid,r,c+1,curr,ret);
        dfs(grid,r,c-1,curr,ret);

    }
};
