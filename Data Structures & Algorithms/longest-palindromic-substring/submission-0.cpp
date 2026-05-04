class Solution {
public:
    string longestPalindrome(string s) {
        // we want to check if some index can be a starting index of a palindrome
        // for that we need to more outward from that index, keeping the length of the longest
        // achievable palindrome in check
        // different checks for the odd len and even lens
        int longestLen = 0, idx = 0;
        for (int i = 0; i < s.size(); i++) {
            // odd len;
            int l = i, r = i;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > longestLen) {
                    longestLen = r - l + 1;
                    idx = l;
                }
                l--;
                r++;
            }

            // even len
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > longestLen) {
                    longestLen = r - l + 1;
                    idx = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(idx, longestLen);
    }
};
