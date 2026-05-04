class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<string> res;

        for (string& word: words) {
            bool flag = false;
            for (int i = 0; i < m && !flag; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] != word[0]) continue;
                    if (backtrack(board, i, j, word, 0)) {
                        res.push_back(word);
                        flag = true;
                        break;
                    }
                }
            }
        }

        return res;
    }

    bool backtrack(vector<vector<char>>& board, int r, int c, string& word, int pos) {
        if (pos == word.size()) return true;

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[pos]) {
            return false;
        }

        board[r][c] = '*';

        bool ret = backtrack(board, r + 1, c, word, pos + 1) || 
        backtrack(board, r - 1, c, word, pos + 1) || 
        backtrack(board, r, c + 1, word, pos + 1) || 
        backtrack(board, r, c - 1, word, pos + 1);

        board[r][c] = word[pos];
        return ret;
    }
};
