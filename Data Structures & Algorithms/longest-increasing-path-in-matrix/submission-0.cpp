class Solution {
public:
    // dp[i][j] -> longest path len starting from i, j
    vector<vector<int>> dp;
    int m, n;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != 0) return dp[i][j];

        dp[i][j] = 1;

        for (auto [dx, dy] : dirs) {
            int nx = i + dx;
            int ny = j + dy;

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[nx][ny] <= matrix[i][j]) {
                continue;
            }

            dp[i][j] = max(dp[i][j], 1 + dfs(nx, ny, matrix));
        }

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(m, vector<int>(n, 0));

        int maxLen = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxLen = max(maxLen, dfs(i, j, matrix));
            }
        }

        return maxLen;
    }
};
