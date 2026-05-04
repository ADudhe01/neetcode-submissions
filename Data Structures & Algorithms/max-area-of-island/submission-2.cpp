class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i >= m || i < 0 || j >= n || j < 0 ||grid[i][j] == 0) return 0;

        int area = 1;
        grid[i][j] = 0;

        for (auto [xi, xj] : dirs) {
            int ni = i + xi, nj = j + xj;
            area += dfs(grid, ni, nj);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, dfs(grid, i, j));
            }
        }

        return maxArea;
    }
};
