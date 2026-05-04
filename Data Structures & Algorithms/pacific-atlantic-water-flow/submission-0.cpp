class Solution {
private:
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    int m, n;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& vis) {
        vis[r][c] = true;

        for (auto d : dirs) {
            int nr = r + d.first;
            int nc = c + d.second;

            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if (vis[nr][nc])
                continue;

            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(heights, nr, nc, vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        pacific.resize(m, vector<bool>(n, false));
        atlantic.resize(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, n - 1, atlantic);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, pacific);
            dfs(heights, m - 1, j, atlantic);
        }

        vector<vector<int>> res;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};
