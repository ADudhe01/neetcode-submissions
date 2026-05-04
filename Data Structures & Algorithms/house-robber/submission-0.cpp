class Solution {
public:
    // for each index, choose it or not
    // recurrence condition max(nums[i] + dp(nums, i + 2), dp(nums, i + 1));
    vector<int> memo;
    int n;
    int dp(vector<int>& nums, int idx) {
        if (idx >= n) return 0;

        if (memo[idx] != -1) return memo[idx];

        return memo[idx] = max(nums[idx] + dp(nums, idx + 2), dp(nums, idx + 1));
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memo.resize(n, -1);


        return dp(nums, 0);
    }
};
