//
// Created by ��һ�� on 2020/5/19.
// Q416���ָ�Ⱥ��Ӽ�
//
#include "util.h"

class Solution {
public:
    /**
     * ������Էָ�,��ÿһ���ֵĺ�һ��Ϊ������ȫ��Ԫ�صĺ͵�һ��,
     * ���,�����ת��Ϊ�Ӽ������ҵ���һ���Ӽ�,�Ӽ���Ϊԭ���Ϻ͵�һ��(������û��ݷ�),�������ڵݹ�,�����˳�ʱ�����
     */
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        } else {
            return findSumRecursive(nums, sum / 2, 0);
        }
    }

    bool findSumRecursive(vector<int>& nums, int remain, int current_position) {
        if (remain == 0) {
            return true;
        }
        for (int i = current_position; i < nums.size(); i++) {
            if (remain - nums[current_position] >= 0 && findSumRecursive(nums, remain - nums[current_position], i + 1)) {
                return true;
            }
        }
        return false;
    }

    /**
     * ������ ����ʹ�û��ݷ�,����Ϊ��������,��һ�����ϼ�¼��ǰ������õĺͣ���Ϊ����Ԫ�ؾ�Ϊ����������˽���¼��ЩС��һ��ĺͼ��ɣ�
     * ʱ�临�Ӷ�O(N^2)
     */
    bool canPartition1(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        } else {
            unordered_set<int> prob_sum;
            prob_sum.insert(0);
            int target = sum / 2;
            if (target == 0) {
                return true;
            }
            for (int i = 0; i < nums.size(); i++) {
                unordered_set<int> temp_set;
                for (auto j = prob_sum.begin(); j != prob_sum.end(); j++) {
                    if (nums[i] + j._M_cur->_M_v() == target) {
                        return true;
                    } else if (nums[i] + j._M_cur->_M_v() < target) {
                        temp_set.insert(nums[i] + j._M_cur->_M_v());
                    }
                }
                for (auto j = temp_set.begin(); j != temp_set.end(); j++) {
                    prob_sum.insert(j._M_cur->_M_v());
                }
            }
        }
        return false;
    }

    /**
     * ���ö�̬�滮��˼��,������ת��Ϊ����ı�������
     * dp[i][j] ��������ǰi�����ܷ��������j
     * ԭ����Ľ⼴Ϊ dp[nums.size()][sum / 2]
     * dp[i][j] = dp[i - 1][j](��װ��i����Ʒ) || dp[i-1][j - ��i����Ʒ������]
     * �㷨��ʱ�临�ӶȺͿռ临�Ӷȶ�ΪO(MN) (����N��Ԫ�ظ���,M������Ԫ�غ͵�һ��)
     */
    bool canPartition2(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // �����������
        if (sum % 2 != 0) {
            return false;
        }
        if (sum == 0) {
            return true;
        }
        // ����dp����
        bool dp[nums.size() + 1][sum / 2 + 1];
        // ��dp�����ʼ��
        for (int i = 1; i < (sum / 2 + 1); i++) {
            dp[0][i] = false;
        }
        for (int i = 0; i < nums.size() + 1; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i < nums.size() + 1; i++) {
            for (int j = 1; j < (sum / 2 + 1); j++) {
                bool with_current = (j - nums[i - 1]) >= 0 ? dp[i-1][j - nums[i-1]] : false;
                bool without_current = dp[i-1][j];
                dp[i][j] = with_current || without_current;
            }
        }
        return dp[nums.size()][sum / 2];
    }
};
