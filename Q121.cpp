//
// Created by 孙一恒 on 2020/4/5.
// Q121、买股票的最佳时机I
//


#include "util.h"

class Solution {
public:
    /**
     * 笨逼法,蛮力尝试以每一天作为买入,后面天作为卖出,找出最大的方案
     * 时间复杂度O(n^2)、空间复杂度O(1),超时
     */
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                max_profit = max(max_profit, prices[j] - prices[i]);
            }
        }
        return max_profit;
    }

    /**
     * 动态规划
     * 蛮力法中对于第i天买入的股票，我们计算其在第i天之后每一天的利润,然后取最大值
     * 动态规划中我们只需计算dp[i],i是第i天到最后一天股票价格的最大值即可
     * 时间复杂度O(n),空间复杂度O(n)
     */
    int maxProfit1(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int dp[prices.size()], max_profit = 0;
        dp[prices.size() - 1] = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--) {
            dp[i] = max(prices[i], dp[i + 1]);
        }
        for (int i = 0; i < prices.size() - 1; i++) {
            max_profit = max(max_profit, dp[i + 1] - prices[i]);
        }
        return max_profit;
    }
};
