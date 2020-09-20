//
// Created by 孙一恒 on 2020/4/21.
// Q322、零钱兑换
//
#include "util.h"

class Solution {
public:
    /**
     * 简单考虑,发现这个问题可以用回溯法来递归解决,但是时间复杂度过高,因为存在大量的重叠子问题
     * 改用动态规划,dp[i]代表i元钱所需的最小钱币数量,状态转移方程: dp[i] = 1 + min(dp[i - coins])
     * 时间复杂度O(n), n为amount,空间复杂度O(n)
     */
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++) {
            int min_coins = INT_MAX;
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] >= 0) {
                    min_coins = min(min_coins, 1 + dp[i - coin]);
                }
            }
            dp[i] = (INT_MAX == min_coins) ? -1 : min_coins;
        }
        return dp[amount];
    }

    /**
     * 贪心 + 剪枝
     * 我们对coins按从大到小进行排序,利用回溯法,贪心的先尽可能查找使用大面额钱币的组合方案,如果找不到,就回溯尝试用稍小一点的面额
     * 但是要注意:我们通过这种方式找出的第一个结果并不一定就是问题的正解,例：对于面额[1,7,10] 表示金额的最小硬币数量为2(7 + 7), 而不是10 + 1 + 1 + 1 + 1
     * 我们之所以这里采取贪心策略是为了进行剪枝,提高算法的时间效率
     */
    int result = INT_MAX;

    int coinChange1(vector<int>& coins, int amount) {
        // 对coins降序排序(sort函数默认是升序的)
        sort(coins.begin(), coins.end(), greater<int>());
        backtrack(coins, amount, 0, 0);
        if (result == INT_MAX) {
            return -1;
        } else {
            return result;
        }
    }

    void backtrack(vector<int>& coins, int remain_amount, int current_coin_num, int position) {
        if (position == coins.size()) {
            return;
        }
        int coin_num = remain_amount / coins[position];
        // 找到了问题的一个解
        if (remain_amount % coins[position] == 0) {
            result = min(result, coin_num + current_coin_num);
            return;
        }
        // 注意下面两种剪枝的不同，上面这种极大的提高了时间效率，使用下面的直接超时
        for (int i = coin_num; i >= 0 && current_coin_num + i < result; i--) {
            backtrack(coins, remain_amount - i * coins[position], current_coin_num + i, position + 1);
        }
//        for (int i = coin_num; i >= 0; i--) {
//            if (current_coin_num + i < result) {
//                backtrack(coins, remain_amount - i * coins[position], current_coin_num + i, position + 1);
//            }
//        }
    }
};