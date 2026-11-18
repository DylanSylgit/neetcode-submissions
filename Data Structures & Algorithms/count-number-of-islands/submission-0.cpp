class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for (int r = 0; r < grid.size(); r ++) {
            for (int c = 0; c < grid[r].size(); c++) {
                if (grid[r][c] == '0') continue;
                dfs(ret,grid,r,c);
                ret ++;
            }
        }

        return ret;
    }

    void dfs(int& ret, vector<vector<char>>& grid, int r, int c){
        if (r >= grid.size() or r < 0 
            or c < 0 or c >= grid[r].size() or grid[r][c] == '0'){
                return;
            }



        grid[r][c] = '0';
        dfs(ret,grid,r+1,c);
        dfs(ret,grid,r-1,c);
        dfs(ret,grid,r,c+1);
        dfs(ret,grid,r,c-1);


    }
};
