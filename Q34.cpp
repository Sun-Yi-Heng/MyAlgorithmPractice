
//
// Created by ��һ�� on 2020/2/4.
// Q34�������������в���Ԫ�صĵ�һ�������һ��λ��
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * ����1:���ȶ��ֲ���,Ȼ����ǰ�����һ������ȷ������
     * һ�������ʱ�临�Ӷ�ΪO(lgn),�������vector�е�targetԪ�ع��࣬���ܻ��˻���O(n)
     */
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        int start = 0;
        int end = nums.size() - 1;
        int middle;
        while (start <= end) {
            middle = (start + end) / 2;
            if (nums[middle] < target) {
                start = middle + 1;
            } else if (nums[middle] > target) {
                end = middle - 1;
            } else {
                // �ֱ���ǰ���������,��ȷ�����䷶Χ
                result[0] = middle;
                result[1] = middle;
                int i = middle - 1;
                while (i >= start) {
                    if (nums[i] == target) {
                        result[0] = i;
                    }
                    i--;
                }
                i = middle + 1;
                while (i <= end) {
                    if (nums[i] == target) {
                        result[1] = i;
                    }
                    i++;
                }
                break;
            }
        }
        return result;
    }
    /**
     * ����2:��ȡ����Ķ������������ѵ���ֱ�ȡ��ǰ�������Ҳ������������,ȡ�������ԵĲ���
     */
};