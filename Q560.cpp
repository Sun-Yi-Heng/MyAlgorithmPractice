//
// Created by ��һ�� on 2020/5/24.
// Q560����ΪK��������
//
#include "util.h"

class Solution {
public:
    /**
     * ����1:����ʹ�ñ��Ʒ���:ͨ������������������ĺ�,�ж����Ƿ����K,���շ��ؼ������ļ������
     * ʱ�临�Ӷ�ΪO(n^2)��Ȼ��ʱ
     */
    int subarraySum(vector<int>& nums, int k) {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (k == sum) {
                    counter++;
                }
            }
        }
        return counter;
    }

    /**
     * ����2:ʹ��ǰ׺��,��preSum[i] �����Ŵ�nums[0]��nums[i - 1]����Ԫ�صĺ�
     * ����(i��j֮����������) = preSum[j + 1] - preSum[i]
     * ���㷨��ʱ�临�Ӷ���δO(n^2),�����õ���˼���������
     */
    int subarraySum1(vector<int>& nums, int k) {
        int counter = 0;
        int preSum[nums.size() + 1];
        preSum[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (preSum[j + 1] - preSum[i] == k) {
                    counter++;
                }
            }
        }
        return counter;
    }

    /**
     * ����3:��������ǰ׺�͵�˼��,���ù�ϣ����ǰ׺�͵ĳ��ִ���
     * �����㵽ĳһǰ׺��ʱ������ͨ����ϣ�����ֱ��ȷ��ǰ���ж��ٵ�ǰ׺������ ����ǰǰ׺�͡� - ��ǰ��ǰ׺�͡� == k
     * ����,���㷨��ʱ�临�ӶȽ�ΪO(N)
     * ע������map��ʹ�÷�ʽ...(Ϊɶû�в����Ԫ��Ҳ����ֱ��++ѽ��������
     */
    int subarraySum2(vector<int>& nums, int k) {
        int counter = 0;
        int pre = 0;
        unordered_map<int, int> preSum_times;
        preSum_times[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            auto find_result = preSum_times.find(pre - k);
            counter += find_result == preSum_times.end() ? 0 : find_result->second;
            preSum_times[pre]++;
        }
        return counter;
    }
};

