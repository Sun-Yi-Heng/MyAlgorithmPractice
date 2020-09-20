//
// Created by ��һ�� on 2020/4/21.
// Q322����Ǯ�һ�
//
#include "util.h"

class Solution {
public:
    /**
     * �򵥿���,���������������û��ݷ����ݹ���,����ʱ�临�Ӷȹ���,��Ϊ���ڴ������ص�������
     * ���ö�̬�滮,dp[i]����iԪǮ�������СǮ������,״̬ת�Ʒ���: dp[i] = 1 + min(dp[i - coins])
     * ʱ�临�Ӷ�O(n), nΪamount,�ռ临�Ӷ�O(n)
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
     * ̰�� + ��֦
     * ���Ƕ�coins���Ӵ�С��������,���û��ݷ�,̰�ĵ��Ⱦ����ܲ���ʹ�ô����Ǯ�ҵ���Ϸ���,����Ҳ���,�ͻ��ݳ�������Сһ������
     * ����Ҫע��:����ͨ�����ַ�ʽ�ҳ��ĵ�һ���������һ���������������,�����������[1,7,10] ��ʾ������СӲ������Ϊ2(7 + 7), ������10 + 1 + 1 + 1 + 1
     * ����֮���������ȡ̰�Ĳ�����Ϊ�˽��м�֦,����㷨��ʱ��Ч��
     */
    int result = INT_MAX;

    int coinChange1(vector<int>& coins, int amount) {
        // ��coins��������(sort����Ĭ���������)
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
        // �ҵ��������һ����
        if (remain_amount % coins[position] == 0) {
            result = min(result, coin_num + current_coin_num);
            return;
        }
        // ע���������ּ�֦�Ĳ�ͬ���������ּ���������ʱ��Ч�ʣ�ʹ�������ֱ�ӳ�ʱ
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