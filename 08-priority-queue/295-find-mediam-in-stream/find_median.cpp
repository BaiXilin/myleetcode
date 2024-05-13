class MedianFinder {
public:
    // a max heap for the numbers on the left of median
    priority_queue<int> leftHeap;
    // a min heap for the numbers on the right of median
    priority_queue<int, vector<int>, greater<int>> rightHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // decide which part this num belongs to
        if(rightHeap.empty() || num <= rightHeap.top())
            leftHeap.push(num);
        else
            rightHeap.push(num);

        // when adding a number, keep the balance between two heaps
        if(rightHeap.size() > leftHeap.size() + 1) {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        } else if(leftHeap.size() > rightHeap.size() + 1) {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
    }
    
    double findMedian() {
        if(leftHeap.size() == rightHeap.size())
            return (leftHeap.top() + rightHeap.top()) / 2.0;
        else if(leftHeap.size() > rightHeap.size())
            return leftHeap.top();
        else
            return rightHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
