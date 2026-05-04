class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> cols(9), rows(9), squares(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                char num = board[i][j];
                if (cols[j].find(num) != cols[j].end()) return false;
                else cols[j].insert(num);

                if (rows[i].find(num) != rows[i].end()) return false;
                else rows[i].insert(num);

                int index = (i / 3) * 3 + (j / 3);
                if (squares[index].find(num) != squares[index].end()) return false;
                else squares[index].insert(num);
            }
        }

        return true;
    }
};
