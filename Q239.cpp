//
// Created by 孙一恒 on 2020/3/27.
// Q239、滑动窗口最大值
//

#include "util.h"

class Solution {
public:
    /**
     * 最朴素的解法,我们控制滑动窗口从左到右滑动,每次都从所有的元素中比较,找出最大值
     * 时间复杂度O(kN),空间复杂度O(1)
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i + k - 1 < nums.size(); i++) {
            result.push_back(getMax(nums, i, i + k - 1));
        }
        return result;
    }

    int getMax(vector<int> &nums, int startIndex, int endIndex) {
        int result = nums[startIndex];
        for (int i = startIndex + 1; i <= endIndex; i++) {
            result = max(result, nums[i]);
        }
        return result;
    }

    /**
     * 方法二:动态规划法
     * 利用用left和right数组,其第i个元素的值分别代表了其到所属窗口的头和尾的最大值
     * 这样从i开始,从j结束的窗口最大值=max(left[j], right[i])
     * 时间复杂度O(N),空间复杂度O(N)
     */
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int> result;
        int left[nums.size()], right[nums.size()];
        // 计算right和left数组
        for (int i = 0; i < nums.size(); i += k) {
            int startIndex = i;
            int endIndex = min((int)nums.size() - 1, i + k - 1);
            int maxLeft = INT_MIN;
            int maxRight = INT_MIN;
            for (int j = startIndex; j <= endIndex; j++) {
                maxLeft = max(maxLeft, nums[j]);
                left[j] = maxLeft;
            }
            for (int j = endIndex; j >= startIndex; j--) {
                maxRight = max(maxRight, nums[j]);
                right[j] = maxRight;
            }
        }
        for (int i = 0; i <= nums.size() - k; i++) {
            int startIndex = i;
            int endIndex = i + k - 1;
            result.push_back(max(right[startIndex], left[endIndex]));
        }
        return result;
    }

//    class MaxQueue {
//    public:
//        // 队列头和队列尾
//        ListNode* head;
//        ListNode* tail;
//        // 辅助队列的队头和队尾
//        ListNode* maxHead;
//        ListNode* maxTail;
//        int currentMax;
//
//        MaxQueue() {
//            head = new ListNode(-1);
//            tail = head;
//            maxHead = new ListNode(-1);
//            maxTail = maxHead;
//        }
//
//        void push(int val) {
//            ListNode* node = new ListNode(val);
//            tail->next = node;
//            tail = tail->next;
//            if ()
//        }
//
//        int pop() {
//            int result = head->next->val;
//            head->next = head->next->next;
//            return result;
//        }
//
//        void getMin() {
//
//        }
//    };
};

