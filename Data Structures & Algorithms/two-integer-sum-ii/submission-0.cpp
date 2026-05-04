class Solution {
public:
    // binary search or tp
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size() - 1; i++) {
            int comp = target - numbers[i];
            int l = i + 1, r = numbers.size() - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (numbers[mid] == comp) return {i + 1, mid + 1};
                else if (numbers[mid] > comp) r = mid - 1;
                else l = mid + 1;
            }
        }

        return {};
    }
};
