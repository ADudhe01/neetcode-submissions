class Solution {
public:
    vector<int> memo;
    int n;
    int dp(vector<int>& cost, int i) {
        // dont need to pay any more as you've passed the last element
        if (i >= n) return 0;

        if (memo[i] != -1) return memo[i];

        return memo[i] = cost[i] + min(dp(cost, i + 1), dp(cost, i + 2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        memo.resize(n, -1);

        return min(dp(cost, 0), dp(cost, 1));
    }
};
