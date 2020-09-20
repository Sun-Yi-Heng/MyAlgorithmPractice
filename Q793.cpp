//
// Created by 孙一恒 on 2020/5/30.
// 793、每日温度
//

#include "util.h"

class Solution {
public:
    /**
     * 方法1:蛮力法,对于每一个位置,我们都依次向后搜索
     * 时间复杂度O(n^2)
     */
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result;
        result.resize(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            for (int j = i + 1; j < T.size(); j++) {
                if (T[j] > T[i]) {
                    result[i] = j - i;
                    break;
                }
            }
        }
        return result;
    }

    /**
     * 方法2:在蛮力法的基础上,加上一些优化,即:如果后面的数字大于等于其前1个数字,则可以直接接着上一个数字比较到的位置
     * 继续进行比较,仍然超时,最坏情况下的时间复杂度仍未O(n^2)
     */
    vector<int> dailyTemperatures1(vector<int>& T) {
        vector<int> result;
        result.resize(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            if (i - 1 >= 0 && T[i] >= T[i - 1]) {
                for (int j = max(result[i - 1] + i - 1, i + 1); j < T.size(); j++) {
                    if (T[j] > T[i]) {
                        result[i] = j - i;
                        break;
                    }
                }
            }  else {
                for (int j = i + 1; j < T.size(); j++) {
                    if (T[j] > T[i]) {
                        result[i] = j - i;
                        break;
                    }
                }
            }
        }
        return result;
    }

    /**
     * 方法3:由于题目给出了温度的范围[30,100],对于位置i的温度T[i],我们只需要温度在(T[i], 100]之间
     * 且下标值大于i的下标中最小的那个下标j,因此,我们从后往前遍历,用数组minIndex[t]记录温度为t的当前最小下标
     * 随着便利的进行不断更新minIndex即可
     * 时间复杂度为O(n * 70) (70为温度的范围)
     */
    vector<int> dailyTemperatures3(vector<int>& T) {
        vector<int> result;
        vector<int> minIndex;
        result.resize(T.size(), 0);
        minIndex.resize(101, INT_MAX);
        for (int i = T.size() - 1; i >= 0; i--) {
            int j = INT_MAX;
            for (int t = T[i] + 1; t <= 100; t++) {
                j = min(j, minIndex[t]);
            }
            if (j != INT_MAX) {
                result[i] = j - i;
            }
            minIndex[T[i]] = i;
        }
        return result;
    }

    /**
     * 方法4:对原算法进行修改,使用栈来记录当前待设置的元素
     * 如果来的元素大于栈顶元素,则pop直到栈为空并设置相应result或者当前元素小于等于栈顶元素
     * 如果来的元素小于等于栈顶元素,则压栈
     * 最后在栈中的元素相应位置result为0
     * 时间复杂度O(N)!
     */
    vector<int> dailyTemperatures2(vector<int>& T) {
        vector<int> result;
        if (T.size() == 0) {
            return result;
        }
        result.resize(T.size(), 0);
        stack<int> my_stack;
        for (int i = 0; i < T.size(); i++) {
            while (my_stack.size() != 0 && T[my_stack.top()] < T[i]) {
                int top_index = my_stack.top();
                my_stack.pop();
                result[top_index] = i - top_index;
            }
            my_stack.push(i);
        }
        while (my_stack.size() != 0 ) {
            int top_index = my_stack.top();
            my_stack.pop();
            result[top_index] = 0;
        }
        return result;
    }
};
