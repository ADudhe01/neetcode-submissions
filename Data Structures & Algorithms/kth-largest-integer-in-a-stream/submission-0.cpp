class KthLargest {
private:
    // max heap - largest element on top
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k_val;
public:
    KthLargest(int k, vector<int>& nums) {
        k_val = k;
        for (int num: nums) min_heap.push(num);

        while (min_heap.size() > k) {
            min_heap.pop();
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        int overflow = min_heap.size() - k_val;
        while (overflow--) {
            min_heap.pop();
        }
        
        return min_heap.top();
    }
};
