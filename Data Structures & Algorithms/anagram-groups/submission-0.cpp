class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // maps chars and their frequencies for each string
        vector<map<char, int>> vecMaps;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++) {
            map<char, int> mp;
            for (int j = 0; j < strs[i].size(); j++) {
                mp[strs[i][j]]++;
            }

            bool flag = false;
            for (int j = 0; j < vecMaps.size(); j++) {
                if (mp == vecMaps[j]) {
                    flag = true;
                    ans[j].push_back(strs[i]);
                    break;
                }
            }

            if (!flag) {
                vecMaps.push_back(mp);
                ans.push_back({strs[i]});
            }
        }

        return ans;
    }
};
