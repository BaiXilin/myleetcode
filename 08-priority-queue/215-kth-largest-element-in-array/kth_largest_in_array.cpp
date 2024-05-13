class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // maintain a min heap with max size of k
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // we are trying to find the kth largest element
        // so only care about the value greater than the current min in minHeap
        for(auto num : nums) {
            // insert num into minHeap
            minHeap.push(num);

            // maintain heap size to k
            if(minHeap.size() > k)
                minHeap.pop();
        }

        return minHeap.top();
    }
};
