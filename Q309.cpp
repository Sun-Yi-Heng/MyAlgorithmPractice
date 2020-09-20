//
// Created by 孙一恒 on 2020/4/5.
// 买股票的最佳时机含冷冻期
//

#include "util.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int dp[prices.size()][2];
        for (int i = 0; i < prices.size(); i++) {
            if (i - 2 < 0) {
                if (i - 1 < 0) {
                    // 注意:对于dp[i-1][1]和dp[i-2][1],如果出现越界,其值应该为-∞,而不是0
                    dp[i][0] = max(0, INT_MIN + prices[i]);
                    dp[i][1] = max(INT_MIN, 0 - prices[i]);
                } else {
                    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                    dp[i][1] = max(dp[i - 1][1], 0 - prices[i]);
                }
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
            }
        }
        return dp[prices.size() - 1][0];
    }
};

