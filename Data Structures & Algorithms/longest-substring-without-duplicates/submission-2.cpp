class Solution {
public:
    // "x z z y" -> answer should be: 2
    //    i j
    // maxLen = 2, i = 0
    // 
    int lengthOfLongestSubstring(string s) {
        if (!s.size()) return 0;

        unordered_set<char> st;
        st.insert(s[0]);
        int maxLen = 1, i = 0;

        for (int j = 1; j < s.size(); j++) {
            if (st.find(s[j]) != st.end()) {
                while (s[i] != s[j]) {
                    // remove the characters that are being skipped
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            st.insert(s[j]);
        }

        return maxLen;
    }
};
