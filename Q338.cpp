//
// Created by ��һ�� on 2020/4/30.
// Q338������λ����
//
#include "util.h"

class Solution {
public:
    /**
     * ����һ:ͨ��շת�����ȷ��ÿ�����Ķ����Ʊ�ʾ�ж��ٸ�1,ʱ�临�Ӷ�O(nlgn)
     */
    vector<int> countBits(int num) {
        vector<int> result;
        int current = 0, one_num = 0;
        for (int i = 0; i <= num; i++) {
            current = i;
            one_num = 0;
            while (current != 0) {
                if (current % 2 == 1) {
                    one_num++;
                }
                current /= 2;
            }
            result.push_back(one_num);
        }
        return result;
    }

    /**
     * ������Ƕ��ڶ����Ƶ��˽�,���Է��ֺ������ĵ�λ��������̾��Ƕ�ǰ�������ظ�
     */
    vector<int> countBits1(int num) {
        vector<int> result;
        if (num == 0) {
            result.push_back(0);
            return result;
        }
        result.push_back(0);
        result.push_back(1);
        int current_num = 1;
        for (int current_cycle_length = 2; current_num <= num; current_cycle_length = current_cycle_length * 2) {
            for (int i = 0; i <= current_cycle_length && current_num <= num; i++, current_num++) {
                result.push_back(result[i] + 1);
            }
        }
        return result;
    }

    /**
     * ����3:
     * ��������n������n-1����λ������������õ��Ľ��������n��ĩβ1���0�Ľ��,�ظ�������̣�ֱ������n���0
     * ѭ���Ĵ�����������n�Ķ����Ʊ�ʾ��1�ĸ���
     * ʱ�临�Ӷȿ�����Ϊ��O(n),Ҳ������Ϊ��O(nlgn),�뷽��1�Ƚ��ٶȸ���
     */
    vector<int> countBits2(int num) {
        vector<int> result;
        int current_count = 0, n;
        for (int i = 0; i <= num; i++) {
            current_count = 0, n = i;
            while (n != 0) {
                n &= (n - 1);
                current_count++;
            }
            result.push_back(current_count);
        }
        return result;
    }
};
