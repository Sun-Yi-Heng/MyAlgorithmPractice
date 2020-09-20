//
// Created by 孙一恒 on 2020/5/28.
// Q621、任务调度
//

#include "util.h"

class Solution {
public:

    static bool myCompare(int back, int front) {
        return back > front;
    }

    /**
     * 采用贪心思想,对于所有任务,我们每次执行那些可以执行的数量最多的任务
     * 时间复杂度O(N),N为任务总数
     */
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> times;
        times.resize(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            times[tasks[i] - 'A']++;
        }
        sort(times.begin(), times.end(), myCompare);
        int time = 0;
        while (times[0] != 0) {
            // 执行当前这一轮任务
            int current_time = 0;
            for (int i = 0; i <= n; i++) {
                if (times[0] == 0) {
                    break;
                }
                if (i <= 25 && times[i] > 0) {
                    times[i]--;
                }
                current_time++;
            }
            sort(times.begin(), times.end(), myCompare);
            time += current_time;
        }
        return time;
    }


    /**
     * 不再每次都进行排序,转而使用优先队列来记录当前剩余次数的顺序
     */
    int leastInterval1(vector<char>& tasks, int n) {
        priority_queue<int> times_queue;
        vector<int> times;
        int result = 0;
        times.resize(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            times[tasks[i] - 'A']++;
        }
        for (int i = 0; i < times.size(); i++) {
            if (times[i] != 0) {
                times_queue.push(times[i]);
            }
        }
        while (times_queue.size() != 0) {
            priority_queue<int> temp_queue;
            int current_time = 0;
            for (int i = 0; i <= n; i++) {
                if (times_queue.size() == 0 && temp_queue.size() != 0) {
                    current_time++;
                } else if (times_queue.size() == 0 && temp_queue.size() == 0) {
                    break;
                } else {
                    int top = times_queue.top();
                    times_queue.pop();
                    if (top > 1) {
                        temp_queue.push(top - 1);
                    }
                }
            }
            result += current_time;
            while (temp_queue.size() != 0) {
                times_queue.push(temp_queue.top());
                temp_queue.pop();
            }
        }
        return result;
    }

    /**
     * 方法3:使用桶思想,首先找到数量最多的任务,这样,根据冷却时间,我们可以算出最少用时
     * 然后根据其他任务的数量决定我们的最终用时。
     */
    int leastInterval2(vector<char>& tasks, int n) {
        int result = 0;
        vector<int> times;
        times.resize(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            times[tasks[i] - 'A']++;
        }
        sort(times.begin(), times.end(), myCompare);
        if (times[0] == 0) {
            return 0;
        }
        int min_time = (times[0] - 1) * (n + 1) + 1;
        for (int i = 1; i < times.size(); i++) {
            if (times[i] == times[0]) {
                min_time++;
            }
        }
        return tasks.size() <= min_time ? min_time : tasks.size();
    }
};

