//
// Created by ��һ�� on 2020/5/25.
// Q1248������������
//
#include "util.h"

class Solution {
public:
    /**
     * ����Q560�Ľⷨ,���㷨��ʱ�临�Ӷ�ΪO(n)
     * ʹ��ǰ׺�������
     */
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> num_times_map;
        num_times_map[0] = 1;
        int current_odd_number = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                current_odd_number++;
            }
            result += num_times_map[current_odd_number - k];
            num_times_map[current_odd_number]++;
        }
        return result;
    }

    /**
     * ����𷽷�1:����map�еļ�ֵһ����0 ~ nums.size֮��,���ֱ��������������map���Ӹ�Ч.
     * ͬʱ,ʹ��λ������Լ���������
     */
    int numberOfSubarrays1(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = 0;
        vector<int> num_times;
        num_times.resize(nums.size() + 1, 0);
        num_times[0] = 1;
        int current_odd_number = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & 1) == 1) {
                current_odd_number++;
            }
            if (current_odd_number - k >= 0) {
                result += num_times[current_odd_number - k];
            }
            num_times[current_odd_number]++;
        }
        return result;
    }
};

