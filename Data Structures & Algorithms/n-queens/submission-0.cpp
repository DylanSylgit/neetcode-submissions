using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string r(n,'.');
            board.push_back(r);
        }
        dfs(board,0,0,n);
        return res;

    }
    void dfs(vector<string>& board, int row, int queens, const int& n) {
        if (row == n) {
            if (queens == n) {
                res.push_back(board);
                return;
            }
            else {
                return;
            }
        }

        for (int c = 0; c < n; ++c) {
            if (check(board,row,c,n) == true) {
                board[row][c] = 'Q';
            }
            else {
                continue;
            }
            dfs(board,row+1,queens+1,n);
            board[row][c] = '.';
        }
    }
    bool check(vector<string>& board, int row, int col, const int& n) {
        for (int r = row; r >= 0; r--) {
            if (board[r][col] == 'Q') return false;
        }
        int r = row;
        int c = col;
        while (r >= 0 and c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }
        r = row;
        c = col;
        while (r >= 0 and c < n) {
            if (board[r][c] == 'Q') return false;
            r--;
            c++;
        }

        return true;
    }
};
