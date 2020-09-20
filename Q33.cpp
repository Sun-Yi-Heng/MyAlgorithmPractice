//
// Created by 孙一恒 on 2020/2/3.
// Q33、搜索旋转排序数组
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 方法1:
     */
    int search1(vector<int>& nums, int target) {
        int index = -1;
        int length = nums.size();
        int left = 0;
        int right = length - 1;
        int middle;
        while (left <= right) {
            middle = (left + right) / 2;
            // 当问题规模较小的时候,直接比较得出结果
            if (right - left <= 3) {
                for (int i = left; i < right; i++) {
                    if (nums[i] == target) {
                        return i;
                    }
                }
                break;
            }
            // 左侧严格递增,说明旋转区间出现在右侧
            if (nums[left] < nums[middle]) {
                // 确定target处于左侧区间,且左侧严格递增,直接在其中二分搜索即可
                if (target <= nums[middle] && target >= nums[left]) {
                    return binary_search(nums, left, middle, target);
                }
                // target不处于左侧区间,则去右侧区间搜索
                else {
                    left = middle + 1;
                }
            }
            // 左侧不严格递增,则旋转区间出现在右侧
            else {
                if (target <= nums[right] && target >= nums[middle]) {
                    return binary_search(nums, middle, right, target);
                }
                // target不处于右侧区间,则取左侧搜索
                else {
                    right = middle - 1;
                }
            }
        }
        return -1;
    }

    int binary_search(vector<int>& nums, int start, int end, int target) {
        int middle;
        while (start <= end) {
            middle = (start + end) / 2;
            if (nums[middle] < target) {
                start = middle + 1;
            } else if (nums[middle] > target) {
                end = middle - 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};

