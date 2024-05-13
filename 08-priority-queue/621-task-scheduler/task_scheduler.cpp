class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cycle = -1;  // count which cycle we are in
        priority_queue<int> taskQueue; // ignoring task char
        unordered_map<char, int> taskList;  // unique task as key, number of execution as value

        // count the number of executions of tasks
        for(auto task : tasks)
            taskList[task]++;

        // insert tasks into a max heap with num of exec as key
        for(auto & it : taskList)
            taskQueue.push(it.second);   // heap only stores frequency

        // greedily schedule the most frequent task first
        // frequency, time when ready
        queue<pair<int, int>> taskBuffer;   // executed task stay here to cool down

        // exit when both the heap and queue are empty
        while(!taskQueue.empty() || !taskBuffer.empty()) {
            cycle++;
            // prioritize the buffer (more frequent tasks are temp in buffer)
            if(!taskBuffer.empty() && taskBuffer.front().second == cycle) {
                int execTaskFreq = taskBuffer.front().first;
                taskBuffer.pop();
                // the task has cooled down, add back to heap for scheduling
                taskQueue.push(execTaskFreq);
            }

            // only ready tasks are in the heap
            // greedily schedule the next task (the most frequent task)
            if(!taskQueue.empty()) {
                // execute the most frequent task in the heap
                int execTaskFreq = taskQueue.top() - 1;
                taskQueue.pop();

                // adds that task to the buffer only if it needs more execution
                if(execTaskFreq > 0)
                    taskBuffer.push(make_pair(execTaskFreq, cycle + n + 1));
            } 
        }

        return cycle + 1;
    }
};
