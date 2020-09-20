//
// Created by ��һ�� on 2020/5/22.
// Q494��Ŀ���
//

#include "util.h"

class Solution {
public:
    /**
     * ����1:ʹ�û��ݷ��������,����ÿһ���ڵ�,����������֧,+��ǰ����-��ǰ��,������п��ܵ����
     * ʱ�临�Ӷ�ΪO(2^n),nΪ�ڵ�ĸ���
     */
    int findTargetSumWays(vector<int>& nums, int S) {
        int result = 0;
        getResult(nums, S, 0, 0, result);
        return result;
    }

    void getResult(vector<int>& nums, int S, int current_index, int current_sum, int& result) {
        if (current_index == nums.size()) {
            if (current_sum == S) {
                result++;
            }
            return;
        }
        getResult(nums, S, current_index + 1, current_sum + nums[current_index], result);
        getResult(nums, S, current_index + 1, current_sum - nums[current_index], result);
    }

    /**
     * ʹ�ö�̬�滮,��Ŀ�и���"�����ʼ�Ͳ�����1000"����Ϣ,��ʾ�����ǿ���ʹ�ö�̬�滮�㷨
     * �����ڱ��������װ���ǲ�װ,������仯Ϊ"װ����"����"װ����"
     * dp[i][j] = dp[i-1][j - nums[i]] + dp[i-1][j + nums[i]]
     */
    int findTargetSumWays1(vector<int>& nums, int S) {
        if (nums.size() == 0) {
            return 0;
        }
        int dp[nums.size()][2001];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = -1000; j <= 1000; j++) {
                dp[i][j + 1000] = 0;
                if (i - 1 < 0) {
                    if (j + 1000 == nums[i] || j + 1000 == -nums[i]) {
                        dp[i][j + 1000] = 1;
                    }
                } else {
                    int left = (j - nums[i] + 1000) >= 0 ?  dp[i - 1][j - nums[i] + 1000] : 0;
                    int right = (j + nums[i] + 1000) <= 2000 ? dp[i - 1][j + nums[i] + 1000] : 0;
                    dp[i][j + 1000] = left + right;
                }
            }
        }
        return dp[nums.size() - 1][S + 1000];
    }
};

