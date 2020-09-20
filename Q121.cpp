//
// Created by ��һ�� on 2020/4/5.
// Q121�����Ʊ�����ʱ��I
//


#include "util.h"

class Solution {
public:
    /**
     * ���Ʒ�,����������ÿһ����Ϊ����,��������Ϊ����,�ҳ����ķ���
     * ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1),��ʱ
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
     * ��̬�滮
     * �������ж��ڵ�i������Ĺ�Ʊ�����Ǽ������ڵ�i��֮��ÿһ�������,Ȼ��ȡ���ֵ
     * ��̬�滮������ֻ�����dp[i],i�ǵ�i�쵽���һ���Ʊ�۸�����ֵ����
     * ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
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
