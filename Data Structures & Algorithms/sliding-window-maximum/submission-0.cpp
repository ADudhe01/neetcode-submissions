class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxEle(n - k + 1, INT_MIN);

        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j < k; j++) {
                if (nums[i + j] > maxEle[i]) {
                    maxEle[i] = nums[i + j];
                }
            }
        }

        return maxEle;
    }
};
