class Solution {
public:
    vector<vector<int>> memo;
    int dp(int m, int n) {
        if (m == 0 && n == 0) return 1;
        if (m < 0 || n < 0) return 0;

        if (memo[m][n] != -1) return memo[m][n];

        return memo[m][n] = dp(m - 1, n) + dp(m, n - 1);
    }
    int uniquePaths(int m, int n) {
        memo.resize(m, vector<int>(n, -1));
        return dp(m - 1, n - 1);
    }
};
