class Solution {
private:
    int m, n;
public:
    // only the 'O's on the border of the board cannot be surrounded
    // mark all the border ones by '#' and leave rest alone
    // at the end turn '#' to 'O' and 'O' to 'X'
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                turn(board, i, 0);
            }

            if (board[i][n - 1] == 'O') {
                turn(board, i, n - 1);
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                turn(board, 0, j);
            }

            if (board[m - 1][j] == 'O') {
                turn(board, m - 1, j);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

    void turn(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;

        board[r][c] = '#';

        turn(board, r + 1, c);
        turn(board, r - 1, c);
        turn(board, r, c + 1);
        turn(board, r, c - 1);
    }
};
