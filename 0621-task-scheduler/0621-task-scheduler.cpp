class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char ele : tasks) {
            freq[ele - 'A']++;
        }
        priority_queue<int> max_heap;
        for (int ele : freq) {
            if (ele != 0) {
                max_heap.push(ele);
            }
        }
        int total_time = 0;
        while (!max_heap.empty()) {
            int cycle = n + 1;
            vector<int> temp;
            int task_count = 0;
            while (cycle > 0 && !max_heap.empty()) {
                int current_task = max_heap.top();
                max_heap.pop();

                if (current_task - 1 > 0) {
                    temp.push_back(current_task - 1);
                }
                task_count++;
                cycle--;
            }
            for (int ele : temp) {
                max_heap.push(ele);
            }
            total_time += max_heap.empty() ? task_count : (n + 1);
        }
        return total_time;
    }
};