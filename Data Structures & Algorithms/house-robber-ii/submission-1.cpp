class Solution {
public:
    int n;
    int dp(vector<int> &nums, int idx, vector<int> &memo) {
        if (idx >= n - 1) return 0;

        if (memo[idx] != -1) return memo[idx];

        return memo[idx] = max(nums[idx] + dp(nums, idx + 2, memo), dp(nums, idx + 1, memo));
    }
    int rob(vector<int>& nums) {
        n = nums.size();

        if (n == 1) return nums[0];

        // create two arrays from nums (0..n-2) and (1..n-1)
        vector<int> includeFirst(n-1, 0), includeLast(n-1, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) includeFirst[i] = nums[i];
            else if (i == n - 1) includeLast[i - 1] = nums[i];
            else {
                includeFirst[i] = nums[i];
                includeLast[i - 1] = nums[i];
            }
        }

        vector<int> memo1(n - 1, -1), memo2(n - 1, -1);
        
        return max(dp(includeFirst, 0, memo1),dp(includeLast, 0, memo2));
    }
};
