class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> res;

        // Push the first k elements into pq
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        
        res.push_back(pq.top().first); // First window max

        for (int i = k; i < nums.size(); i++) {
            pq.push({nums[i], i}); // Insert new element

            // Remove elements that are out of the window range
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            res.push_back(pq.top().first);
        }

        return res;
    }
};