class Solution {
public:
    // each index: choose (x(-1) / )
    int dfs(int idx, vector<int>& nums, int target) {
        if (idx == nums.size()) {
            if (target == 0) return 1;
            else return 0;
        }

        return dfs(idx + 1, nums, target - nums[idx]) + dfs(idx + 1, nums, target + nums[idx]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, nums, target);
    }
};
