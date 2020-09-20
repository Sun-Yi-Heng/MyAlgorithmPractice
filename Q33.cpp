//
// Created by ��һ�� on 2020/2/3.
// Q33��������ת��������
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * ����1:
     */
    int search1(vector<int>& nums, int target) {
        int index = -1;
        int length = nums.size();
        int left = 0;
        int right = length - 1;
        int middle;
        while (left <= right) {
            middle = (left + right) / 2;
            // �������ģ��С��ʱ��,ֱ�ӱȽϵó����
            if (right - left <= 3) {
                for (int i = left; i < right; i++) {
                    if (nums[i] == target) {
                        return i;
                    }
                }
                break;
            }
            // ����ϸ����,˵����ת����������Ҳ�
            if (nums[left] < nums[middle]) {
                // ȷ��target�����������,������ϸ����,ֱ�������ж�����������
                if (target <= nums[middle] && target >= nums[left]) {
                    return binary_search(nums, left, middle, target);
                }
                // target�������������,��ȥ�Ҳ���������
                else {
                    left = middle + 1;
                }
            }
            // ��಻�ϸ����,����ת����������Ҳ�
            else {
                if (target <= nums[right] && target >= nums[middle]) {
                    return binary_search(nums, middle, right, target);
                }
                // target�������Ҳ�����,��ȡ�������
                else {
                    right = middle - 1;
                }
            }
        }
        return -1;
    }

    int binary_search(vector<int>& nums, int start, int end, int target) {
        int middle;
        while (start <= end) {
            middle = (start + end) / 2;
            if (nums[middle] < target) {
                start = middle + 1;
            } else if (nums[middle] > target) {
                end = middle - 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};

