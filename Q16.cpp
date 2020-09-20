//
// Created by ��һ�� on 2020/9/14.
// Q16����ӽ�������֮��
//
#include "util.h"

class Solution {
public:
    /**
     * ���ú�"Q15������֮��"���Ƶ�˼·���
     * �������� + ˫ָ�뷨 ����������ö��ʱ�临�Ӷ���O(N^2) ���͵� O(N)
     * ��ʱ�临�Ӷ�ΪO(N^2)
     */
    int threeSumClosest(vector<int>& nums, int target) {
        // ��������
        int result = 0, min_distance = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // �����ظ�����
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right] - target;
                int sum = nums[i] + nums[left] + nums[right];
                // ��ʱ����
                if (abs(current_sum) < min_distance) {
                    min_distance = abs(current_sum);
                    result = sum;
                }
                if (current_sum > 0) {
                    right--;
                } else if (current_sum < 0) {
                    left++;
                } else {
                    return sum;
                }
            }
        }
        return result;
    }
};

