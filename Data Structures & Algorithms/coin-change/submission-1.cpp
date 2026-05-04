class Solution {
public:
    unordered_map<int, int> memo;
    int dp(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        if (memo.count(amount)) return memo[amount];

        int ans = INT_MAX;
        for (int coin: coins) {
            if (amount - coin >= 0) {
                int res = dp(coins, amount - coin);
                if (res != INT_MAX) {
                    ans = min(ans, 1 + res);
                }
            }
        }

        return memo[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dp(coins, amount);
        return minCoins == INT_MAX ? -1 : minCoins;
    }
};
