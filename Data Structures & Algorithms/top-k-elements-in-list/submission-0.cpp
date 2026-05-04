class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (int i = 0; i < k; i++) {
            pair<int, int> maxFreq(-1,-1);
            for (auto &pair: mp) {
                if (pair.second > maxFreq.second) {
                    maxFreq.first = pair.first;
                    maxFreq.second = pair.second;
                }
            }
            mp.erase(maxFreq.first);

            ans.push_back(maxFreq.first);
        }

        return ans;
    }
};
