class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st;

        for (int n: nums) st.insert(n);

        return st.size() != nums.size();
    }
};