class MedianFinder {
private:
    // maxHeap -> smallest half of stream
    // minHeap -> larger half of the stream
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (minHeap.empty() || num > minHeap.top()) minHeap.push(num);
        else maxHeap.push(num);

        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (maxHeap.size() > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    template <typename T>
    void printQueues(T heap) {
        while (!heap.empty()) {
            cout << heap.top() << " ";
            heap.pop();
        }
        cout << endl;
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }

        printQueues(minHeap);
        printQueues(maxHeap);

        return minHeap.top();
    }
};
