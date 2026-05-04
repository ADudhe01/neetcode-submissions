class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = 1, currMin = 1, res = nums[0];

        for (int num: nums) {
            int temp = currMax * num;
            currMax = max(max(currMax * num, currMin * num), num);
            currMin = min(min(temp, currMin * num), num);

            res = max(res, currMax);
        }

        return res;
    }
};
