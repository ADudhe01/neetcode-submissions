class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> freq(128, 0);
        for (char c : t)
            freq[c]++;

        int start = 0, minLen = INT_MAX, minStart = 0;
        int required = t.size();

        for (int end = 0; end < s.size(); end++) {
            if (freq[s[end]] > 0)
                required--;

            freq[s[end]]--;

            while (required == 0) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }

                freq[s[start]]++;

                if (freq[s[start]] > 0)
                    required++;

                start++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
