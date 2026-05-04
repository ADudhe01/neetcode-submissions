class Solution {
public:
    // prefProd:   1   1   1   1
    //             1.  1.  2.  8
    // suffixProd: 48  24  6   1
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefProd(n, 1), suffixProd(n, 1);

        for (int i = 1; i < n; i++) {
            prefProd[i] = nums[i - 1] * prefProd[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixProd[i] = nums[i + 1] * suffixProd[i + 1];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = prefProd[i] * suffixProd[i];
        }

        return ans;
    }
};
