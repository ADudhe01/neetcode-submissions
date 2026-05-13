class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // end maxSum there and start new or take that element
            maxSum = max(nums[i], maxSum + nums[i]);
            res = max(res, maxSum);
        }

        return res
        ;
    }
};
