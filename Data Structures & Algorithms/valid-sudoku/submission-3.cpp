class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int,std::vector<int>> rows;
        std::unordered_map<int,std::vector<int>> cols;
        std::unordered_map<int,std::vector<int>> squares;
        for (int row = 0; row < board.size(); row++) {

            for (int col = 0; col < 9; col++) {
                int square = ((row/3)*3 + (col/3));
                char num = board[row][col];

                int n = static_cast<int>(num);

                if (num == '.') continue;

                if (std::find(rows[row].begin(),rows[row].end(),n) != rows[row].end()) {
                    return false;
                }
                if (std::find(cols[col].begin(),cols[col].end(),n) != cols[col].end()) {
                    return false;
                }
                if (std::find(squares[square].begin(),squares[square].end(),n) != squares[square].end()) {
                    return false;
                }

                rows[row].push_back(n);
                cols[col].push_back(n);
                squares[square].push_back(n);
            }
        }
        return true;
    }
};
