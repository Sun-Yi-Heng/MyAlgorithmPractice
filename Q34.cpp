
//
// Created by 孙一恒 on 2020/2/4.
// Q34、在排序数组中查找元素的第一个和最后一个位置
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 方法1:首先二分查找,然后向前后向后一次搜索确定区间
     * 一般情况下时间复杂度为O(lgn),但是如果vector中的target元素过多，可能会退化到O(n)
     */
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        int start = 0;
        int end = nums.size() - 1;
        int middle;
        while (start <= end) {
            middle = (start + end) / 2;
            if (nums[middle] < target) {
                start = middle + 1;
            } else if (nums[middle] > target) {
                end = middle - 1;
            } else {
                // 分别向前和向后搜索,以确定区间范围
                result[0] = middle;
                result[1] = middle;
                int i = middle - 1;
                while (i >= start) {
                    if (nums[i] == target) {
                        result[0] = i;
                    }
                    i--;
                }
                i = middle + 1;
                while (i <= end) {
                    if (nums[i] == target) {
                        result[1] = i;
                    }
                    i++;
                }
                break;
            }
        }
        return result;
    }
    /**
     * 方法2:采取纯粹的二分搜索，即搜到后分别取当前的左侧和右侧区间继续搜索,取消掉线性的部分
     */
};