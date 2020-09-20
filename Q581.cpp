//
// Created by ��һ�� on 2020/5/25.
// Q581���������������
//
#include "util.h"

class Solution {
public:
    /**
     * ���ȴ�ͷ��ʼ���ҵ�һ���ƻ������λ��,Ȼ���ĩβ����Ѱ�ҵ�һ���ƻ������λ��
     * ���Ų������������������ֵ����Сֵ
     * ����ٷֱ��ͷ�ʹ�ĩβ��ʼ��������,�ֱ���������е�һ��������СֵԪ�غ�С�����ֵԪ�ص��±ꡣ
     * Ȼ���������±�֮��������������Ҫ�������С���䡣
     * ʱ�临�Ӷ�O(n)
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
        // �����������,ֱ�ӷ��ؽ��
        if (front_un_order == -1) {
            return 0;
        }
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i - 1] > nums[i]) {
                end_un_order = i;
                break;
            }
        }
        // �������򲿷ֵ����ֵ����Сֵ
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
     * ������:ֱ�Ӷ���������,Ȼ��Ƚ�ǰ��֮�������,����ȷ����С���򳤶�
     * ʱ�临�Ӷ��������㷨������ΪO(nlgn)
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
     * ������:����ջ,�ֱ��������߽�����ұ߽�
     * ʱ�临�Ӷ�ΪO(n)
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
