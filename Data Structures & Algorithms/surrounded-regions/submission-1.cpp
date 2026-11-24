using namespace std;
class Solution {
public:
    int m;
    int n;
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int r = 0; r < m; r ++) {
            dfs(board, r, 0);
            dfs(board, r, n-1 );
        }

        for (int c = 0; c < n; c++) {
            dfs(board,0,c);
            dfs(board,m-1,c);
        }

        for (int r = 0; r < m; r ++) {
            for (int c= 0; c < n; c++){
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board,int r, int c) {
        
        if (r >= m or c >=n or c <0 or r < 0) return;

        if (board[r][c] != 'O') return;

        board[r][c] = '#';

        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            dfs(board,nr,nc);

        }
    }


};
