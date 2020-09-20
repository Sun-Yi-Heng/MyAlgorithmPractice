//
// Created by 孙一恒 on 2020/2/23.
// Q84、柱状图中最大的矩形
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * 使用蛮力动态规划,从前向后逐渐计算最大矩形面积,对于每个柱子，子问题的解要么不包含这跟柱子，要么是这跟柱子到前面的某根柱子
     * 之间所有柱子得到的，因此我们蛮力的找出所有可能的解，从而选出最优的那个。
     * 三重循环，时间复杂度为O(n ^ 3)，空间复杂度O(1), 提交后发现超时
     */
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            // 包括自身在内,当前最大区域可能是由从i开始，到前面任意连续的柱子组成的,它们组成的矩形的面积=(i - j + 1) * minHeight
            for (int j = i; j >= 0; j--) {
                int minHeight = heights[j];
                for (int k = j; k <= i; k++) {
                    minHeight = min(minHeight, heights[k]);
                }
                int currentArea = minHeight * (i - j + 1);
                largestArea = max(largestArea, currentArea);
            }
        }
        return largestArea;
    }

    /**
     * 优化上面的求解过程,消除最内层循环,我们用二维数组记录下从位置i到位置j之间的柱子的最小高度
     * 时间复杂度为O(n ^ 2), 空间复杂度为O(n ^ 2)
     **/
    int largestRectangleArea1(vector<int>& heights) {
        int largestArea = 0;
        if (heights.size() == 0) {
            return 0;
        }
        int height[heights.size()][heights.size()];
        for (int i = 0; i < heights.size(); i++) {
            // 包括自身在内,当前最大区域可能是由从i开始，到前面任意连续的柱子组成的,它们组成的矩形的面积=(i - j + 1) * minHeight
            for (int j = i; j >= 0; j--) {
                int minHeight;
                if (j == i) {
                    minHeight = heights[i];
                    height[j][i] = heights[i];
                } else {
                    minHeight = min(height[j][i - 1], heights[i]);
                    height[j][i] = minHeight;
                }
                int currentArea = minHeight * (i - j + 1);
                largestArea = max(largestArea, currentArea);
            }
        }
        return largestArea;
    }


    /**
     * 我们发现完全没有必要用二维数组记录下各个区间的最小高度,直接在第二层循环的时候顺带计算即可
     * 时间复杂度为O(n ^ 2), 空间复杂度O(1)，仍然超时
     * @return
     */
    int largestRectangleArea2(vector<int>& heights) {
        int largestArea = 0;
        if (heights.size() == 0) {
            return 0;
        }
        for (int i = 0; i < heights.size(); i++) {
            // 包括自身在内,当前最大区域可能是由从i开始，到前面任意连续的柱子组成的,它们组成的矩形的面积=(i - j + 1) * minHeight
            int minHeight = heights[i];
            for (int j = i; j >= 0; j--) {
                minHeight = min(heights[j], minHeight);
                int currentArea = minHeight * (i - j + 1);
                largestArea = max(largestArea, currentArea);
            }
        }
        return largestArea;
    }

    /**
     * 采用分治法求解
     */


    /**
     * 采用栈结构,从左向右遍历矩形数组,如果当前元素>=栈顶元素,则将其压入栈中,否则,弹出栈。遍历结束后将栈中剩余元素一次弹出
     * 当元素弹出时,我们就可以计算以当前元素高度决定的举行面积,为此，我们要确定左右边界,想清楚左右边界究竟是什么是解决这道题的关键
     */
    int largestRectangleArea5(vector<int>& heights) {
        if (heights.size() == 0) {
            return 0;
        }
        int maxArea = 0;
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            if (s.size() == 0 || heights[s.top()] <= heights[i]) {
                s.push(i);
            } else {
                int rightIndex = i;
                while (s.size() != 0 && heights[s.top()] > heights[i]) {
                    int index = s.top();
                    s.pop();
                    int currentArea = 0;
                    if (s.size() == 0) {
                        currentArea = (rightIndex - 0) * heights[index];
                    } else {
                        currentArea = (rightIndex - s.top() - 1) * heights[index];
                    }
                    maxArea = max(maxArea, currentArea);
                }
                s.push(i);
            }
        }
        int rightIndex = s.top();
        // 这里的while循环和for循环中的不同
        while (s.size() != 1) {
            int index = s.top();
            s.pop();
            int currentArea = (rightIndex - s.top()) * heights[index];
            maxArea = max(maxArea, currentArea);
        }
        int currentArea = heights.size() * heights[s.top()];
        maxArea = max(maxArea, currentArea);
        return maxArea;
    }
};