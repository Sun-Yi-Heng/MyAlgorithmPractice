//
// Created by ��һ�� on 2020/3/27.
// Q239�������������ֵ
//

#include "util.h"

class Solution {
public:
    /**
     * �����صĽⷨ,���ǿ��ƻ������ڴ����һ���,ÿ�ζ������е�Ԫ���бȽ�,�ҳ����ֵ
     * ʱ�临�Ӷ�O(kN),�ռ临�Ӷ�O(1)
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
     * ������:��̬�滮��
     * ������left��right����,���i��Ԫ�ص�ֵ�ֱ�������䵽�������ڵ�ͷ��β�����ֵ
     * ������i��ʼ,��j�����Ĵ������ֵ=max(left[j], right[i])
     * ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(N)
     */
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int> result;
        int left[nums.size()], right[nums.size()];
        // ����right��left����
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
//        // ����ͷ�Ͷ���β
//        ListNode* head;
//        ListNode* tail;
//        // �������еĶ�ͷ�Ͷ�β
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

