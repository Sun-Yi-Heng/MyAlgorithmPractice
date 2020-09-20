//
// Created by 孙一恒 on 2020/5/19.
// Q416、分割等和子集
//
#include "util.h"

class Solution {
public:
    /**
     * 如果可以分割,则每一部分的和一定为集合中全部元素的和的一半,
     * 因此,问题就转化为从集合中找到其一个子集,子集和为原集合和的一半(这里采用回溯法),但是由于递归,出现了超时的情况
     */
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        } else {
            return findSumRecursive(nums, sum / 2, 0);
        }
    }

    bool findSumRecursive(vector<int>& nums, int remain, int current_position) {
        if (remain == 0) {
            return true;
        }
        for (int i = current_position; i < nums.size(); i++) {
            if (remain - nums[current_position] >= 0 && findSumRecursive(nums, remain - nums[current_position], i + 1)) {
                return true;
            }
        }
        return false;
    }

    /**
     * 方法二 不再使用回溯法,而改为遍历数组,用一个集合记录当前可能求得的和（因为数组元素均为正整数，因此仅记录那些小于一半的和即可）
     * 时间复杂度O(N^2)
     */
    bool canPartition1(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        } else {
            unordered_set<int> prob_sum;
            prob_sum.insert(0);
            int target = sum / 2;
            if (target == 0) {
                return true;
            }
            for (int i = 0; i < nums.size(); i++) {
                unordered_set<int> temp_set;
                for (auto j = prob_sum.begin(); j != prob_sum.end(); j++) {
                    if (nums[i] + j._M_cur->_M_v() == target) {
                        return true;
                    } else if (nums[i] + j._M_cur->_M_v() < target) {
                        temp_set.insert(nums[i] + j._M_cur->_M_v());
                    }
                }
                for (auto j = temp_set.begin(); j != temp_set.end(); j++) {
                    prob_sum.insert(j._M_cur->_M_v());
                }
            }
        }
        return false;
    }

    /**
     * 利用动态规划的思想,将问题转化为特殊的背包问题
     * dp[i][j] 代表着用前i个数能否组成数字j
     * 原问题的解即为 dp[nums.size()][sum / 2]
     * dp[i][j] = dp[i - 1][j](不装第i个物品) || dp[i-1][j - 第i个物品的重量]
     * 算法的时间复杂度和空间复杂度都为O(MN) (其中N是元素个数,M是所有元素和的一半)
     */
    bool canPartition2(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // 特殊情况处理
        if (sum % 2 != 0) {
            return false;
        }
        if (sum == 0) {
            return true;
        }
        // 申请dp数组
        bool dp[nums.size() + 1][sum / 2 + 1];
        // 对dp数组初始化
        for (int i = 1; i < (sum / 2 + 1); i++) {
            dp[0][i] = false;
        }
        for (int i = 0; i < nums.size() + 1; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i < nums.size() + 1; i++) {
            for (int j = 1; j < (sum / 2 + 1); j++) {
                bool with_current = (j - nums[i - 1]) >= 0 ? dp[i-1][j - nums[i-1]] : false;
                bool without_current = dp[i-1][j];
                dp[i][j] = with_current || without_current;
            }
        }
        return dp[nums.size()][sum / 2];
    }
};
