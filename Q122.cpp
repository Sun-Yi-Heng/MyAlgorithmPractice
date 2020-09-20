//
// Created by ��һ�� on 2020/4/5.
// Q122�����Ʊ�����ʱ��II
//

#include "util.h"

class Solution {
public:
    /**
     * ��������������,��ٷ���̫����
     * �۲��֪,��ѵķ��������ҳ�prices��ÿ�����������������,��ÿ������Ŀ�ͷ����,��ÿ�������ĩβ����
     * ������õ����������ѧ����,ò�ƿ�������һ��̰�Ĳ��ԣ�
     * ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)
     */
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int window_start = 0;
        // ��ĩβ�����ڱ�
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
