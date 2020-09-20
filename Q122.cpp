//
// Created by 孙一恒 on 2020/4/5.
// Q122、买股票的最佳时机II
//

#include "util.h"

class Solution {
public:
    /**
     * 由于允许多次买入,穷举法不太可行
     * 观察可知,最佳的方案就是找出prices中每个连续且升序的区间,在每个区间的开头买入,在每个区间的末尾卖出
     * 这样获得的利润最大（数学解释,貌似可以理解成一种贪心策略）
     * 时间复杂度O(N),空间复杂度O(1)
     */
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int window_start = 0;
        // 在末尾插入哨兵
        prices.push_back(0);
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= prices[i - 1]) {
                continue;
            } else {
                if ((i - 1) - window_start > 0) {
                    max_profit += prices[i - 1] - prices[window_start];
                }
                window_start = i;
            }
        }
        return max_profit;
    }
};
