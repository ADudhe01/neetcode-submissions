class Solution {
public:
    int m, n;
    // set of pair so that we dont use the same cell for a different word
    set<pair<int, int>> cells;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // last parameter is for the word size
                if (backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int row, int col, int word_size) {
        // positive condition
        if (word_size == word.size()) return true;

        if (row >= m || row < 0 || col >= n | col < 0 
            || board[row][col] !=  word[word_size] || cells.count({row, col})) {
            return false;
        }

        cells.insert({row, col});
        bool res =  backtrack(board, word, row + 1, col, word_size + 1) ||
                    backtrack(board, word, row - 1, col, word_size + 1) ||
                    backtrack(board, word, row, col + 1, word_size + 1) ||
                    backtrack(board, word, row, col - 1, word_size + 1);
        cells.erase({row, col});

        return res;
    }


};
