class Solution {
public:
    int ROWS, COLS;

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (helper(board,word,r,c,0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, const string& word,int r, int c,int idx) {
        
        // out of bounds, or if board[r][c] != word[idx]
        if (r >= ROWS or r < 0 or c >= COLS or c < 0 or board[r][c] != word[idx]) {
            return false;
        }
        
        if (idx == word.length()-1) {return true;}

        char tmp = board[r][c];
        board[r][c] = '#';

        // board[r][c] == word[idx], proceed
        bool good = helper(board,word,r+1,c,idx+1) or helper(board,word,r-1,c,idx+1) or 
            helper(board,word,r,c+1,idx+1) or helper(board,word,r,c-1,idx+1);
        board[r][c] = tmp;
        return good;

    }

};
