class Solution {
public:
    int calcDist(vector<int> a) {
        return a[0] * a[0] + a[1] * a[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

        vector<vector<int>> ans;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            vector<int> a = {x, y};
            pq.push(make_pair(calcDist(a), a));
        }

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
