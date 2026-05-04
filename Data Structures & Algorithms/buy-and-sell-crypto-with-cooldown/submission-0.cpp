class Solution {
public:
    unordered_map<string, int> memo;
    int dp(int idx, bool canBuy, vector<int>& prices) {
        if (idx >= prices.size()) return 0;

        string key = to_string(idx) + '-' + to_string(canBuy);
        if (memo.count(key)) return memo[key];

        int ifWeCoolDown = dp(idx + 1, canBuy, prices);

        if (canBuy) {
            int buy = dp(idx + 1, false, prices) - prices[idx];
            memo[key] = max(buy, ifWeCoolDown);
        } else {
            int sell = dp(idx + 2, true, prices) + prices[idx];
            memo[key] = max(sell, ifWeCoolDown);
        }

        return memo[key];
    }
    int maxProfit(vector<int>& prices) {
        return dp(0, true, prices);
    }
};
