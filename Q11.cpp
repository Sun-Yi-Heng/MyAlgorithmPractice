//
// Created by 孙一恒 on 2020/6/17.
// Q11、盛最多水的容器
//
#include "util.h"

class Solution {
public:
    /**
     * 方法1:蛮力法
     * 时间复杂度O(N^2),超出了时间限制
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
     * 方法2:使用双指针法,每次移动指针消除绝对不可能的方案
     * 时间复杂度O(N)
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
