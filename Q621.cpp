//
// Created by ��һ�� on 2020/5/28.
// Q621���������
//

#include "util.h"

class Solution {
public:

    static bool myCompare(int back, int front) {
        return back > front;
    }

    /**
     * ����̰��˼��,������������,����ÿ��ִ����Щ����ִ�е�������������
     * ʱ�临�Ӷ�O(N),NΪ��������
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
            // ִ�е�ǰ��һ������
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
     * ����ÿ�ζ���������,ת��ʹ�����ȶ�������¼��ǰʣ�������˳��
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
     * ����3:ʹ��Ͱ˼��,�����ҵ�������������,����,������ȴʱ��,���ǿ������������ʱ
     * Ȼ�������������������������ǵ�������ʱ��
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

