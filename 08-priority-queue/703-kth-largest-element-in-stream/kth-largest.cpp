#include <queue>
#include <vector>
#include <functional>

class KthLargest {
public:
    // use a min heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int k = 0;

    KthLargest(int k, vector<int>& nums) {
        // store all nums into binary heap in min sorted order
        for(auto num : nums)
            minHeap.push(num);

        // Note: possible that nums.size() < k
        this->k = k;
        while(minHeap.size() > k)
            minHeap.pop();
        // guaranteed that minHeap.size() <= k
    }

    // add val to the stream and return the new kth largest element
    int add(int val) {
        // add val to minHeap
        minHeap.push(val);

        // only pop when there are more than k elements in the minHeap
        if(minHeap.size() > k)
            minHeap.pop();

        // guaranteed to have k elements in the minHeap, return the root
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
