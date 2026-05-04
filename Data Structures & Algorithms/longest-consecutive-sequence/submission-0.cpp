class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());

        int maxLen = 0;
        for (int num: nums) {
            if (st.find(num - 1) == st.end()) {
                int len = 1;
                while (st.find(num + len) != st.end()) {
                    len++;
                }

                maxLen = max(len, maxLen);
            }
        }

        return maxLen;
    }
};
