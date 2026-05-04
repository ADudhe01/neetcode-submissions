class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int num = 0; num <= n; num++) {
            int count = 0;
            for (int i = 0; i < 32; i++) {
                count += (num >> i) & 1;
            }

            ans.push_back(count);
        }

        return ans;
    }
};
