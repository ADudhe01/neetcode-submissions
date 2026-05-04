class Solution {
public:
    vector<vector<int>> memo;
    int dp(int idx, int amount, vector<int>& coins) {
        if (idx >= coins.size()) return 0;
        if (amount == 0) return 1;
        if (amount < 0) return 0;

        if (memo[idx][amount] != -1) return memo[idx][amount];

        int take_coin = dp(idx, amount - coins[idx], coins);
        int leave_coin = dp(idx + 1, amount, coins);

        return memo[idx][amount] = take_coin + leave_coin;
    }
    int change(int amount, vector<int>& coins) {
        memo.resize(coins.size(), vector<int>(amount + 1, -1));
        return dp(0, amount, coins);
    }
};
