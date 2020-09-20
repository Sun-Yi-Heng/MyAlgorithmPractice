//
// Created by 孙一恒 on 2020/5/22.
// Q494、目标和
//

#include "util.h"

class Solution {
public:
    /**
     * 方法1:使用回溯法求解问题,对于每一个节点,都有两个分支,+当前数和-当前数,穷举所有可能的情况
     * 时间复杂度为O(2^n),n为节点的个数
     */
    int findTargetSumWays(vector<int>& nums, int S) {
        int result = 0;
        getResult(nums, S, 0, 0, result);
        return result;
    }

    void getResult(vector<int>& nums, int S, int current_index, int current_sum, int& result) {
        if (current_index == nums.size()) {
            if (current_sum == S) {
                result++;
            }
            return;
        }
        getResult(nums, S, current_index + 1, current_sum + nums[current_index], result);
        getResult(nums, S, current_index + 1, current_sum - nums[current_index], result);
    }

    /**
     * 使用动态规划,题目中给出"数组初始和不超过1000"等信息,暗示着我们可以使用动态规划算法
     * 类似于背包问题的装还是不装,该问题变化为"装正的"还是"装负的"
     * dp[i][j] = dp[i-1][j - nums[i]] + dp[i-1][j + nums[i]]
     */
    int findTargetSumWays1(vector<int>& nums, int S) {
        if (nums.size() == 0) {
            return 0;
        }
        int dp[nums.size()][2001];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = -1000; j <= 1000; j++) {
                dp[i][j + 1000] = 0;
                if (i - 1 < 0) {
                    if (j + 1000 == nums[i] || j + 1000 == -nums[i]) {
                        dp[i][j + 1000] = 1;
                    }
                } else {
                    int left = (j - nums[i] + 1000) >= 0 ?  dp[i - 1][j - nums[i] + 1000] : 0;
                    int right = (j + nums[i] + 1000) <= 2000 ? dp[i - 1][j + nums[i] + 1000] : 0;
                    dp[i][j + 1000] = left + right;
                }
            }
        }
        return dp[nums.size() - 1][S + 1000];
    }
};

