class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // heapify the vector into a max heap
        std::priority_queue<int> maxHeap;

        for(auto stone : stones)
            maxHeap.push(stone);

        while(maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); // select two heaviest stones
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();

            if(stone1 < stone2) {
                maxHeap.push(stone2 - stone1);
            } else if(stone2 < stone1) {
                maxHeap.push(stone1 - stone2);
            } // else {
            //      // no stones put back when stone1 == stone2
            // }
        }
        
        // in case there is no stone left in the maxHeap
        if(maxHeap.size() == 0)
            return 0;
        return maxHeap.top();
    }
};
