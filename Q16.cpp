//
// Created by 孙一恒 on 2020/9/14.
// Q16、最接近的三数之和
//
#include "util.h"

class Solution {
public:
    /**
     * 采用和"Q15、三数之和"类似的思路求解
     * 利用排序 + 双指针法 将两个数的枚举时间复杂度由O(N^2) 降低到 O(N)
     * 总时间复杂度为O(N^2)
     */
    int threeSumClosest(vector<int>& nums, int target) {
        // 首先排序
        int result = 0, min_distance = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // 跳过重复数字
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right] - target;
                int sum = nums[i] + nums[left] + nums[right];
                // 及时更新
                if (abs(current_sum) < min_distance) {
                    min_distance = abs(current_sum);
                    result = sum;
                }
                if (current_sum > 0) {
                    right--;
                } else if (current_sum < 0) {
                    left++;
                } else {
                    return sum;
                }
            }
        }
        return result;
    }
};

