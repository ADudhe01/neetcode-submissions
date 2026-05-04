class Solution {
public:
    // each index: choose (x(-1) / )
    map<pair<int,int>, int> memo;
    int dfs(int idx, vector<int>& nums, int target) {
        if (idx == nums.size()) {
            return target == 0;
        }

        if (memo.count({idx, target}))
            return memo[{idx, target}];

        int add = dfs(idx + 1, nums, target - nums[idx]);
        int subtract = dfs(idx + 1, nums, target + nums[idx]);

        return memo[{idx, target}] = add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, nums, target);
    }
};
