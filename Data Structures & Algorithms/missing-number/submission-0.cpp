class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int arr_sum = 0, sum = 0, n = nums.size();

        sum = n * (n + 1)/2;

        for (int i = 0; i < n; i++) {
            arr_sum += nums[i];
        }

        return sum - arr_sum;
        
    }
};
