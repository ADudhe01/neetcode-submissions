class Solution {
public:
    vector<int> memo;
    bool dfs(int idx, string s, vector<string>& wordDict) {
        if (idx == s.size()) return true;

        if (memo[idx] != -1) return memo[idx];

        for (string word: wordDict) {
            if (idx + word.size() <= s.size() && s.substr(idx, word.size()) == word) {
                if (dfs(idx + word.size(), s, wordDict)) return memo[idx] = 1;
            }
        }

        return memo[idx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memo.resize(s.size(), -1);
        return dfs(0, s, wordDict);
    }
};
