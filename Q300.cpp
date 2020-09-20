//
// Created by 孙一恒 on 2020/4/1.
// Q300、最长上升子序列
//
#include "util.h"

class Solution {
public:
    /**
     * 递归的穷举法，通过递归穷举出所有的情况,找出其中最长的那个
     * 最坏情况时间复杂度:T(n) = T(n-1) + T(n-2) + ... + T(1) + O(n) <=> O(n ^ n)
     * 最坏情况下空间复杂度O(n)
     */
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        return recursive(0, -1, nums, 0);
    }

    /**
     * current_position代表当前遍历的起始位置，previous_position代表了上一个选中元素的位置
     * 只要遍历过程中找到了可以递归的子问题,就进一步递归求解,找出所有结果中最大的那一个。
     */
    int recursive(int current_position, int previous_position, vector<int>& nums, int current_length) {
        int max_length = 0;
        for (int i = current_position; i < nums.size(); i++) {
            if (previous_position >= 0) {
                if (nums[i] > nums[previous_position]) {
                    max_length = max(max_length, recursive(i + 1, i, nums, current_length + 1));
                }
            } else {
                max_length = max(max_length, recursive(i + 1, i, nums, current_length + 1));
            }
        }
        return max(current_length, max_length);
    }

    /**
     * 动态规划法求解,dp[i]的含义是从nums的下标0，到下标i且最长子序列包含nums[i]的子问题
     * 状态转移方程: dp[i] = max(dp[j]) + 1 (0 <= j < i && nums[j] < nums[i]
     * 时间复杂度O(n^2), 空间复杂度O(n)
     */
    int lengthOfLIS1(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int dp[nums.size()], max_length = 1;
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_length = max(max_length, dp[i]);
        }
        return max_length;
    }

    /**
     * 方法3:贪心算法 + 动态规划
     * dp[i]代表了长度为i + 1的上升子序列的最小的末尾值。
     * 由于dp数组也是一个升序的序列,如果查找的地方使用二分查找法,则最坏情况下的时间复杂度为O(n*lgn)
     * https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/
     */
    int lengthOfLIS2(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); i++) {
            if (dp.size() == 0 || nums[i] > dp[dp.size() - 1]) {
                dp.push_back(nums[i]);
            } else {
                for (int j = 0; j < dp.size(); j++) {
                    if (nums[i] <= dp[j]) {
                        dp[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return dp.size();
    }
};
