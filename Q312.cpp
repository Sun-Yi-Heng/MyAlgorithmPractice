//
// Created by ��һ�� on 2020/4/20.
// Q312��������
//

#include "util.h"

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int dp[nums.size()][nums.size()];
        for (int gap = 0; gap < nums.size(); gap++) {
            for (int i = 0; i + gap < nums.size(); i++) {
                for (int j = i; j <= i + gap; j++) {
                    int left_part = (j - 1) < i ? 0 : dp[i][j - 1];
                    int right_part = (j + 1) >= nums.size() ? 0 : dp[i][j + 1];
                    dp[i][j] = left_part + right_part + nums[j];
                }
            }
        }
        return dp[0][nums.size() - 1];
    }

    /**
     * ���õݹ���(���ݷ�),�ݹ�ı������п��ܵ����,�������ֵ,�ռ临�Ӷ�O(n), ʱ�临�Ӷ�O(N!)
     */
    int maxCoins1(vector<int>& nums) {
        return getMaxCoinNum(nums, 0);
    }

    int getMaxCoinNum(vector<int>& nums, int current_coins) {
        if (nums.size() == 0) {
            return current_coins;
        }
        int max_coins = 0;
        for (int i = 0; i < nums.size(); i++) {
            int coins = nums[i] * ((i - 1) >= 0 ? nums[i - 1] : 1) * ((i + 1) < nums.size() ? nums[i + 1] : 1);
            int temp = nums[i];
            nums.erase(nums.begin() + i);
            max_coins = max(max_coins, getMaxCoinNum(nums, current_coins + coins));
            nums.insert(nums.begin() + i, temp);
        }
        return max_coins;
    }

    /**
     * ���÷��η�, dp[i][j]����������������i��j,���������м������ʱ�õ����������
     * ״̬ת�Ʒ���: dp[i][j] = max(dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]) (i < k < j) ���൱��k����󱻴��Ƶ�����)
    */
    int maxCoins2(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        // ��������߽�
        nums.insert(nums.begin(), 1);
        nums.insert(nums.begin() + nums.size(), 1);
        int dp[nums.size()][nums.size()];
        for (int gap = 0; gap < nums.size(); gap++) {
            for (int i = 0; i + gap < nums.size(); i++) {
                dp[i][i + gap] = 0;
                for (int k = i + 1; k < i + gap; k++) {
                    int left_part = (k - i) > 1 ? dp[i][k] : 0;
                    int right_part = (i + gap - k) > 1 ? dp[k][i + gap] : 0;
                    dp[i][i + gap] = max(dp[i][i + gap], left_part + right_part + nums[i] * nums[k] * nums[i + gap]);
                }
            }
        }
        return dp[0][nums.size() - 1];
    }
};
