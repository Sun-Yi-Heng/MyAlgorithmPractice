//
// Created by ��һ�� on 2020/4/1.
// Q300�������������
//
#include "util.h"

class Solution {
public:
    /**
     * �ݹ����ٷ���ͨ���ݹ���ٳ����е����,�ҳ���������Ǹ�
     * ����ʱ�临�Ӷ�:T(n) = T(n-1) + T(n-2) + ... + T(1) + O(n) <=> O(n ^ n)
     * �����¿ռ临�Ӷ�O(n)
     */
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        return recursive(0, -1, nums, 0);
    }

    /**
     * current_position����ǰ��������ʼλ�ã�previous_position��������һ��ѡ��Ԫ�ص�λ��
     * ֻҪ�����������ҵ��˿��Եݹ��������,�ͽ�һ���ݹ����,�ҳ����н����������һ����
     */
    int recursive(int current_position, int previous_position, vector<int>& nums, int current_length) {
        int max_length = 0;
        for (int i = current_position; i < nums.size(); i++) {
            if (previous_position >= 0) {
                if (nums[i] > nums[previous_position]) {
                    max_length = max(max_length, recursive(i + 1, i, nums, current_length + 1));
                }
            } else {
                max_length = max(max_length, recursive(i + 1, i, nums, current_length + 1));
            }
        }
        return max(current_length, max_length);
    }

    /**
     * ��̬�滮�����,dp[i]�ĺ����Ǵ�nums���±�0�����±�i��������а���nums[i]��������
     * ״̬ת�Ʒ���: dp[i] = max(dp[j]) + 1 (0 <= j < i && nums[j] < nums[i]
     * ʱ�临�Ӷ�O(n^2), �ռ临�Ӷ�O(n)
     */
    int lengthOfLIS1(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int dp[nums.size()], max_length = 1;
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_length = max(max_length, dp[i]);
        }
        return max_length;
    }

    /**
     * ����3:̰���㷨 + ��̬�滮
     * dp[i]�����˳���Ϊi + 1�����������е���С��ĩβֵ��
     * ����dp����Ҳ��һ�����������,������ҵĵط�ʹ�ö��ֲ��ҷ�,�������µ�ʱ�临�Ӷ�ΪO(n*lgn)
     * https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/
     */
    int lengthOfLIS2(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); i++) {
            if (dp.size() == 0 || nums[i] > dp[dp.size() - 1]) {
                dp.push_back(nums[i]);
            } else {
                for (int j = 0; j < dp.size(); j++) {
                    if (nums[i] <= dp[j]) {
                        dp[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return dp.size();
    }
};
