//
// Created by ��һ�� on 2020/5/21.
// Q448���ҵ�������������ʧ������
//
#include "util.h"

class Solution {
public:
    /**
     * ����1:�������������,Ȼ��ɨ��һ�����鼴��֪��ȱ����ЩԪ����
     * �㷨��ʱ�临�Ӷ�O(nlgn)(�������㷨����), �㷨�Ŀռ临�Ӷ�ΪO(1)
     */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int current_num = 1; // ��1��ʼ�Ƚ�,ͳ��û�г��ֹ�������
        for (int i = 0; i < nums.size(); i++) {
            if (current_num == nums[i]) {
                current_num++;
            } else if (current_num < nums[i]) {
                while (current_num < nums[i]) {
                    result.push_back(current_num);
                    current_num++;
                }
                current_num++;
            }
        }
        while (current_num <= nums.size()) {
            result.push_back(current_num);
            current_num++;
        }
        return result;
    }

    /**
     * ����2:����һ������Ϊnums[size]��bool����,������б���,������ʹ�������Ϊtrue
     * ���㷨��ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ҲΪO(N)
     */
    vector<int> findDisappearedNumbers1(vector<int>& nums) {
        vector<int> result;
        if (nums.size() == 0) {
            return result;
        }
        bool have[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            have[i] = false;
        }
        for (int i = 0; i < nums.size(); i++) {
            have[nums[i] - 1] = true;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!have[i]) {
                result.push_back(i + 1);
            }
        }
        return result;
    }

    /**
     * ����3:ֱ����nums�ϸı�,�㷨��˼��ͷ���2һ��,��Ȼʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(1),������Ϊ�޸���ԭ����
     * ��˲�����������Ҫ��
     */
    vector<int> findDisappearedNumbers2(vector<int>& nums) {
        vector<int> result;
        int index = 0;
        while (index != nums.size()) {
            if (nums[index] == -1) {
                index++;
            } else {
                int temp = nums[index];
                if (nums[nums[index] - 1] != -1) {
                    nums[index] = nums[nums[index] - 1];
                } else {
                    index++;
                }
                nums[temp - 1] = -1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != -1) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
