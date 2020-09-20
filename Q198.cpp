//
// Created by 孙一恒 on 2020/4/23.
// Q198、打家劫舍
//
#include "util.h"

class Solution {
public:
    /**
     * 方法1:通过递归穷举
     * 时间复杂度的推导公式: T(n) = T(n - 2) + T(n - 3), 大约为O(2 ^ n)
     */
    int rob(vector<int>& nums) {
        return recursive(nums, 0, 0);
    }

    int recursive(vector<int>& nums, int position, int current_money) {
        if (position >= nums.size()) {
            return current_money;
        } else if (position == nums.size() - 1) {
            return current_money + nums[position];
        }
        return max(recursive(nums, position + 2, current_money + nums[position]),
                   recursive(nums, position + 3, current_money + nums[position + 1]));
    }

    int rob2(vector<int>& nums) {
        return divide_and_conquer(nums, 0, nums.size() - 1);
    }

    /**
     * 求解nums[left]到nums[right]的子问题的解,根据master定理,时间复杂度在O(n^2) 到 O(n ^ 3)之间
     */
    int divide_and_conquer(vector<int>& nums, int left, int right) {
        if (left > right) {
            return 0;
        } else if (left == right) {
            return nums[left];
        } else if (right - left == 1) {
            return max(nums[left], nums[right]);
        }
        int middle = (left + right) / 2;
        int situation1 = divide_and_conquer(nums, left, middle - 2) + divide_and_conquer(nums, middle + 2, right) + nums[middle];
        int situation2 = divide_and_conquer(nums, left, middle - 1) + divide_and_conquer(nums, middle + 3, right) + nums[middle + 1];
        int situation3 = divide_and_conquer(nums, left, middle - 1) + divide_and_conquer(nums, middle + 2, right);
        return max(situation1, max(situation2, situation3));
    }

    /**
     * 动态规划算法
     * dp[i] 的含义为,小偷从第一户开始到第i户的子问题的解。
     * 状态转移方程: dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
     * 这个方法的时间复杂度为O(n),空间复杂度为O(n)
     */
    int rob1(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int dp[nums.size()], i1, i2;
        for (int i = 0; i < nums.size(); i++) {
            i1 = (i - 1) >= 0 ? dp[i - 1] : 0;
            i2 = (i - 2) >= 0 ? dp[i - 2] : 0;
            dp[i] = max(i1, i2 + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
