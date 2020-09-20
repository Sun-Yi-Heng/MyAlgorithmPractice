//
// Created by ��һ�� on 2020/2/18.
// Q75����ɫ����
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * ����1:����ɨ��,��һ��ͳ�Ƹ�����ɫ������,�ڶ���ֱ�Ӹ�ֵ����.
     * @param nums
     */
    void sortColors(vector<int>& nums) {
        int num[3];
        num[0] = 0;
        num[1] = 0;
        num[2] = 0;
        for (int i = 0; i < nums.size(); i++) {
            num[nums[i]]++;
        }
        for (int i = 0; i < 3; i++) {
            int bias = 0;
            for (int k = 0; k < i; k++) {
                bias += num[k];
            }
            for (int j = 0; j < num[i]; j++) {
                nums[j + bias] = i;
            }
        }
    }

    /**
     * ����2:һ��ɨ��������,����ͨ��˫ָ��������
     */
    void sortColors1(vector<int>& nums) {
        // p0Ϊ0�����ұ߽�,��p2Ϊ2������߽�,iΪ��ǰ���ǵ�Ԫ��
        int p0 = 0, p2 = nums.size() - 1;
        for (int i = 0; i <= p2; i++) {
            if (nums[i] == 0) {
                swap(nums, i, p0);
                p0++;
            } else if (nums[i] == 2) {
                swap(nums, i, p2);
                p2--;
                // ���ڲ�ȷ�����������Ǹ�ʲô,����i--,�Ե�ǰλ�����ж�һ�Ρ�
                i--;
            }
        }
   }

   void swap(vector<int>& nums, int i1, int i2) {
        int temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
    }
};

