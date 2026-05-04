class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool dfs(vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '0') return false;

        grid[i][j] = '0';
        for (auto [xi, xj]: dirs) {
            int ni = i + xi, nj = j + xj;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n) dfs(grid, ni, nj);
        }

        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(grid, i, j)) res++;
            }
        }

        return res;
    }
};
