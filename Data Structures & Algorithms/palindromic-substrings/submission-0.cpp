class Solution {
public:
    int countSubstrings(string s) {
        // at each index check if it can be a start of an odd or even
        // palindromic substring
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            // odd len
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
        }

        return count;
    }
};
