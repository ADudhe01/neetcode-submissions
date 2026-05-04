class Solution {
public:
    // problem: s -> uppercase characters and int k
    // perform at most k replacements to get a longest substr with only one distinct character
    // return that longest substr length

    // X       Y       Y       X      Y
    // start.  

    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int start = 0, maxCount = 0, maxLen = 0;

        for (int end = 0; end < s.size(); end++) {
            freq[s[end] - 'A']++;
            maxCount = max(maxCount, freq[s[end] - 'A']);

            // If more than k replacements needed
            while ((end - start + 1) - maxCount > k) {
                freq[s[start] - 'A']--;
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
