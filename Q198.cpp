//
// Created by ��һ�� on 2020/4/23.
// Q198����ҽ���
//
#include "util.h"

class Solution {
public:
    /**
     * ����1:ͨ���ݹ����
     * ʱ�临�Ӷȵ��Ƶ���ʽ: T(n) = T(n - 2) + T(n - 3), ��ԼΪO(2 ^ n)
     */
    int rob(vector<int>& nums) {
        return recursive(nums, 0, 0);
    }

    int recursive(vector<int>& nums, int position, int current_money) {
        if (position >= nums.size()) {
            return current_money;
        } else if (position == nums.size() - 1) {
            return current_money + nums[position];
        }
        return max(recursive(nums, position + 2, current_money + nums[position]),
                   recursive(nums, position + 3, current_money + nums[position + 1]));
    }

    int rob2(vector<int>& nums) {
        return divide_and_conquer(nums, 0, nums.size() - 1);
    }

    /**
     * ���nums[left]��nums[right]��������Ľ�,����master����,ʱ�临�Ӷ���O(n^2) �� O(n ^ 3)֮��
     */
    int divide_and_conquer(vector<int>& nums, int left, int right) {
        if (left > right) {
            return 0;
        } else if (left == right) {
            return nums[left];
        } else if (right - left == 1) {
            return max(nums[left], nums[right]);
        }
        int middle = (left + right) / 2;
        int situation1 = divide_and_conquer(nums, left, middle - 2) + divide_and_conquer(nums, middle + 2, right) + nums[middle];
        int situation2 = divide_and_conquer(nums, left, middle - 1) + divide_and_conquer(nums, middle + 3, right) + nums[middle + 1];
        int situation3 = divide_and_conquer(nums, left, middle - 1) + divide_and_conquer(nums, middle + 2, right);
        return max(situation1, max(situation2, situation3));
    }

    /**
     * ��̬�滮�㷨
     * dp[i] �ĺ���Ϊ,С͵�ӵ�һ����ʼ����i����������Ľ⡣
     * ״̬ת�Ʒ���: dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
     * ���������ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(n)
     */
    int rob1(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int dp[nums.size()], i1, i2;
        for (int i = 0; i < nums.size(); i++) {
            i1 = (i - 1) >= 0 ? dp[i - 1] : 0;
            i2 = (i - 2) >= 0 ? dp[i - 2] : 0;
            dp[i] = max(i1, i2 + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
