//
// Created by ��һ�� on 2020/3/26.
// Q238����������������ĳ˻�
//

#include "util.h"

class Solution {
public:
    /**
     * ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1),����ʹ���˳���
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        vector<int> result;
        vector<int> zero_index;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_index.push_back(i);
            } else {
                total *= nums[i];
            }
        }
        // ����������0�ĸ������ִ������
        if (zero_index.size() == 0) {
            for (int i = 0; i < nums.size(); i++) {
                result.push_back(total / nums[i]);
            }
        } else if (zero_index.size() == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (i == zero_index[0]) {
                    result.push_back(total);
                } else {
                    result.push_back(0);
                }
            }
        } else {
            for (int i = 0; i < nums.size(); i++) {
                result.push_back(0);
            }
        }
        return result;
    }

    /**
     * ����������е�һ����������Ҫ���ǵõ�������������ĳ˻������Ҳ��������ĳ˻�,Ȼ�����һ�𼴿�
     * ��ֻ��Ҫ���α���������ɣ���һ�μ�����࣬�ڶ��μ����Ҳ࣬ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�O(1)
     */
    vector<int> productExceptSelf1(vector<int>& nums) {
        vector<int> result(nums.size());
        int currentLeft = 1;
        for (int i = 0; i < nums.size(); i++) {
            result[i] = currentLeft;
            currentLeft *= nums[i];
        }
        int currentRight = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] *= currentRight;
            currentRight *= nums[i];
        }
        return result;
    }
};

