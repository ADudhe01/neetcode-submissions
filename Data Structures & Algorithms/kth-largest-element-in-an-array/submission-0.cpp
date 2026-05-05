class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // kth largest -> in a minheap of k elements is the top
        // add only if the top is smaller than the curr number

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num: nums) {
            if (pq.size() >= k) {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            } else {
                pq.push(num);
            }
        }

        return pq.top(); 
    }
};
