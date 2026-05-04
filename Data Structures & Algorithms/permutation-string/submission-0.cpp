class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> freq(26, 0);
        for (char c: s1) freq[c - 'a']++;

        int start = 0;
        for (int end = 0; end < m; end++) {
            freq[s2[end] - 'a']--;
            
            // If window size exceeds n, restore left char
            if (end - start + 1 > n) {
                freq[s2[start] - 'a']++;
                start++;
            }

            // If all frequencies are zero → permutation found
            if (end - start + 1 == n && all_of(freq.begin(), freq.end(), [](int x){ return x == 0; }))
                return true;
        }

        return false;
    }
};
