class Solution {
public:
    class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        endOfWord = false;
        for (int i = 0; i < 26; i ++) {
            children[i] = nullptr;
        }
    }
};
    int rows;
    int cols;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Set up trie
        TrieNode* root = new TrieNode();
        for (string word : words) {
            TrieNode* curr = root;
            for (char c : word) {
                int i = c - 'a';
                if (!curr->children[i]) {
                    curr->children[i] = new TrieNode();
                }
                curr = curr->children[i];
            }
            curr->endOfWord = true;
        }

        rows = board.size();
        cols = board[0].size();

        // Traverse the board
        vector<string> ret;
        string current;
        for (int r = 0; r < rows; r ++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == ' ') continue;
                search(board,ret,current,r,c,root);
            }
        }

        return ret;


    }

    void search(vector<vector<char>>& board, vector<string>& ret, string& curr, int row, int col, TrieNode* node) {
        // out of range or has already been used or node == nullptr
        if (row >= rows or col >= cols 
            or row < 0 or col < 0 
                or board[row][col] == ' '
                    or !node) {
            return;
        }


        char ch = board[row][col];
        int i = ch - 'a';
        if (!node->children[i]) return;
        board[row][col] = ' '; // mark as used
        curr.push_back(ch);
        if (node->children[i]->endOfWord) {
            ret.push_back(curr);
            node->children[i]->endOfWord = false;
        }
        search(board,ret,curr,row+1,col,node->children[i]);
        search(board,ret,curr,row-1,col,node->children[i]);
        search(board,ret,curr,row,col+1,node->children[i]);
        search(board,ret,curr,row,col-1,node->children[i]);

        curr.pop_back();
        board[row][col] = ch;

    }


};