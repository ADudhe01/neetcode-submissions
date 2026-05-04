class Solution {
public:
    /* 
        bfs solution: 
        - first store all the 2s int the queue
        - start the rotting process by popping each element in the queue and rot their 
            subsequent fresh fruit neighbour (min counter for each level)
        - at the end just traverse the whole array and see if there is a 1
    */
    int orangesRotting(vector<vector<int>>& grid) {
        // row, col, time
        queue<tuple<int, int, int>> q;
        int minTime = 0, m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 1});
                }
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            auto [r, c, time] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i].first;
                int nc = c + dirs[i].second;

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != 1) {
                    continue;
                }

                // rot the fresh orange
                grid[nr][nc] = 2;
                minTime = max(minTime, time);
                q.push({nr, nc, time + 1});
            }

        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return minTime;
    }
};
