class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sum;

        backtrack(sum, nums, target, 0);

        return ans;
    }

    void backtrack(vector<int> &sum, vector<int>& nums, int target, int i) {
        if (target == 0) {
            ans.push_back(sum);
            return;
        }

        if (target < 0 || i >= nums.size()) {
            return;
        }

        sum.push_back(nums[i]);
        backtrack(sum, nums, target - nums[i], i);
        sum.pop_back();
        backtrack(sum, nums, target, i + 1);

    }
};
