//
// Created by ��һ�� on 2020/6/17.
// Q11��ʢ���ˮ������
//
#include "util.h"

class Solution {
public:
    /**
     * ����1:������
     * ʱ�临�Ӷ�O(N^2),������ʱ������
     */
    int maxArea(vector<int>& height) {
        int result = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                result = max(result, (j - i) * min(height[i], height[j]));
            }
        }
        return result;
    }

    /**
     * ����2:ʹ��˫ָ�뷨,ÿ���ƶ�ָ���������Բ����ܵķ���
     * ʱ�临�Ӷ�O(N)
     * https://leetcode-cn.com/problems/container-with-most-water/solution/container-with-most-water-shuang-zhi-zhen-fa-yi-do/
     */
    int maxArea1(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int result = 0;
        while (start < end) {
            result = max(result, min(height[start], height[end]) * (end - start));
            if (height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }
        return result;
    }
};
