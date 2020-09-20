//
// Created by 孙一恒 on 2020/2/5.
// Q42、接雨水
//

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * 观察图像,得知我们需要计算的是一个个可以盛放雨水的区间,为此我们需要依次计算每个区间的左边界和右边界
     * 一开始以最左侧作为左边界,0显然不能作为左边界,如果当前左边界的紧邻的下一个柱子更高,显然应该将下一个柱子作为左边界
     * 左边界确定后,向后搜索右边界:当找到高于或等于左边界的柱子时,可以确定其为右边界。如果右侧遍历结束也找不到这样的柱子,则将其中最高的那个作为右边界。
     * 确定左右边界后开始计算该区间可容纳的雨水。
     * 之后将当前右边界作为新的左边界继续计算即可。
     */
    int trap1(vector<int>& height) {
        int rain = 0;
        int left, right;
        left = 0;
        while (left < height.size()) {
            if (height[left] == 0) {
                left++;
            } else {
                // 确定了边界的位置,寻找右侧边界的位置的位置
                right = left + 1;
                if (right >= height.size()) {
                    break;
                }
                if (height[right] >= height[left]) {
                    left = right;
                    continue;
                }
                int max_height = height[right];
                int max_height_index = right;
                for (; right < height.size(); right++) {
                    if (max_height < height[right]) {
                        max_height = height[right];
                        max_height_index = right;
                    }
                    if (height[right] >= height[left]) {
                        break;
                    }
                }
                right = max_height_index;
                int rain_height = min(height[left], height[right]);
                for (int i = left + 1; i < right; i++) {
                    if (height[i] < rain_height) {
                        rain += rain_height - height[i];
                    }
                }
                left = right;
            }
        }
        return rain;
    }

    /**
     * 方法2:采用栈作为容器
     */
//    int trap2(vector<int>& height) {
//        stack<int> index_stack;
//        for (int i = 0; i < height.size(); i++) {
//            if (index_stack.size() == 0 || height)
//        }
//    }
};
