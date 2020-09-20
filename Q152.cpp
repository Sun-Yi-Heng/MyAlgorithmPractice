//
// Created by ��һ�� on 2020/3/17.
// Q152���˻����������
//
#include "util.h"

class Solution {
public:
    /**
     * ����1:�������,�������п��ܵ����,ʱ�临�Ӷ�ΪO(n^3),�ռ临�Ӷ�ΪO(1)
     */
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int current = 1;
                for (int k = i; k <= j; k++) {
                    current *= nums[k];
                }
                result = max(result, current);
            }
        }
        return result;
    }

    /**
     * ����2:
     * �Ż����ǵ�ö�ٷ�,���ǽ�����ļ���ת��Ϊһ���Ե����ϵļ���,�����ظ�����,�����ڶ�̬�滮��
     * ʱ�临�ӶȽ��͵�O(n^2),�ռ临�Ӷ���ߵ�O(n^2)
     */
    int maxProduct1(vector<int>& nums) {
        int product[nums.size()][nums.size()];
        int result = nums[0];
        for (int gap = 0; gap < nums.size(); gap++) {
            for (int i = 0; i + gap < nums.size(); i++) {
                if (i + 1 > i + gap) {
                    product[i][i + gap] = nums[i];
                } else {
                    product[i][i + gap] = product[i][i] * product[i + 1][i + gap];
                }
                result = max(result, product[i][i + gap]);
            }
        }
        return result;
    }

    /**
     * ����3:
     * ����2��LeetCode������stack overflow����,�����������һ���Ż��ռ临�Ӷȵ�O(n)
     * ʱ�临�Ӷ�ΪO(n^2),�ռ临�ӶȽ��͵�O(n)
    */
    int maxProduct2(vector<int>& nums) {
        int previous_product[nums.size()];
        int result = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            previous_product[i] = nums[i];
            result = max(result, previous_product[i]);
        }
        for (int gap = 1; gap < nums.size(); gap++) {
            for (int i = 0; i + gap < nums.size(); i++) {
                previous_product[i] = nums[i] * previous_product[i + 1];
                result = max(result, previous_product[i]);
            }
        }
        return result;
    }


    /**
     * ����3:��̬�滮
     * ��imax��¼�Ե�ǰ�ڵ���Ϊ��ֹ�ڵ��������������
     * ��imin��¼�Ե�ǰ�ڵ���Ϊ��ֹ�ڵ����С���������
     * ����������ÿһ���ڵ���Ϊ��ֹ�ڵ�,����һ�ֱȽϺ󼴿��������Ľ�
     * ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
     */
    int maxProduct3(vector<int>& nums) {
        int imax = 1, imin = 1, result = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                int temp = imax;
                imax = imin;
                imin = temp;
            }
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            result = max(imax, result);
        }
        return result;
    }

};

