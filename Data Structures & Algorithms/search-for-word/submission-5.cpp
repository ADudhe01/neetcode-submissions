class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<char>>& board, int i, int j, const string& word, int index) {
        // 1. Base case: If the current cell doesn't match the word character, return false
        if (board[i][j] != word[index]) return false;
        
        // 2. Base case: If we've successfully matched the last character, we are done
        if (index == word.size() - 1) return true;
        
        // Mark the current cell as visited in-place
        char temp = board[i][j];
        board[i][j] = '#'; 
        
        // Directions array
        static const vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        for (auto [di, dj] : dirs) {
            int ni = i + di, nj = j + dj;
            // Check bounds. Notice we no longer check !visited here.
            // If we visit a '#', it simply fails the first `if` check on the next recursive call.
            if (ni >= 0 && ni < m && nj >= 0 && nj < n) {   
                if (dfs(board, ni, nj, word, index + 1)) return true;
            }
        }

        // Backtrack: Restore the original character to the board
        board[i][j] = temp;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        m = board.size(), n = board[0].size();

        // No visited array needed!
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If DFS finds the word starting from (i, j), return true
                if (dfs(board, i, j, word, 0)) return true;
            }
        }

        return false;
    }
};