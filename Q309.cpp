//
// Created by ��һ�� on 2020/4/5.
// ���Ʊ�����ʱ�����䶳��
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
                    // ע��:����dp[i-1][1]��dp[i-2][1],�������Խ��,��ֵӦ��Ϊ-��,������0
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

