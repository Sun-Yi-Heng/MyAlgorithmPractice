//
// Created by 孙一恒 on 2020/5/25.
// Q581、最短无序子数组
//
#include "util.h"

class Solution {
public:
    /**
     * 首先从头开始查找第一个破坏升序的位置,然后从末尾倒着寻找第一个破坏降序的位置
     * 接着查找这段无序区间的最大值和最小值
     * 最后再分别从头和从末尾开始遍历数组,分别查找数组中第一个大于最小值元素和小于最大值元素的下标。
     * 然后这两个下标之间的区间就是我们要排序的最小区间。
     * 时间复杂度O(n)
     */
    int findUnsortedSubarray(vector<int>& nums) {
        int front_un_order = -1;
        int end_un_order = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                front_un_order = i;
                break;
            }
        }
        // 如果数组有序,直接返回结果
        if (front_un_order == -1) {
            return 0;
        }
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i - 1] > nums[i]) {
                end_un_order = i;
                break;
            }
        }
        // 查找无序部分的最大值和最小值
        int un_order_max = nums[front_un_order];
        int un_order_min = nums[front_un_order];
        for (int i = front_un_order + 1; i <= end_un_order; i++) {
            un_order_max = max(un_order_max, nums[i]);
            un_order_min = min(un_order_min, nums[i]);
        }
        int start_index, end_index;
        for (start_index = 0; start_index < nums.size(); start_index++) {
            if (nums[start_index] > un_order_min) {
                break;
            }
        }
        for (end_index = nums.size() - 1; end_index >= 0; end_index--) {
            if (nums[end_index] < un_order_max) {
                break;
            }
        }
        return end_index - start_index + 1;
    }

    /**
     * 方法二:直接对数组排序,然后比较前后之间的区别,即可确定最小排序长度
     * 时间复杂度由排序算法决定，为O(nlgn)
     */
    int findUnsortedSubarray1(vector<int>& nums) {
        vector<int> v2(nums);
        sort(v2.begin(), v2.end());
        int start_index = -1, end_index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != v2[i]) {
                start_index = i;
                break;
            }
        }
        if (start_index == -1) {
            return 0;
        }
        for (int j = nums.size() - 1; j >= 0; j--) {
            if (nums[j] != v2[j]) {
                end_index = j;
                break;
            }
        }
        return end_index - start_index + 1;
    }

    /**
     * 方法三:借助栈,分别求得最左边界和最右边界
     * 时间复杂度为O(n)
     */
    int findUnsortedSubarray2(vector<int>& nums) {
        stack<int> order_stack;
        int left_boundary = INT_MAX, right_boundary = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (order_stack.size() == 0 || nums[i] >= nums[order_stack.top()]) {
                order_stack.push(i);
            } else {
                while (order_stack.size() != 0 && nums[i] < nums[order_stack.top()]) {
                    order_stack.pop();
                }
                if (order_stack.size() == 0) {
                    left_boundary = 0;
                    break;
                } else {
                    left_boundary = min(left_boundary, order_stack.top() + 1);
                }
            }
        }
        if (left_boundary == INT_MAX) {
            return 0;
        }
        stack<int> reverse_order_stack;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (reverse_order_stack.size() == 0 || nums[i] <= nums[reverse_order_stack.top()]) {
                reverse_order_stack.push(i);
            } else {
                while (reverse_order_stack.size() != 0 && nums[i] > nums[reverse_order_stack.top()]) {
                    reverse_order_stack.pop();
                }
                if (reverse_order_stack.size() == 0) {
                    right_boundary = nums.size() - 1;
                    break;
                } else {
                    right_boundary = max(right_boundary, reverse_order_stack.top() - 1);
                }
            }
        }
        return right_boundary - left_boundary + 1;
    }
};
