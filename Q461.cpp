//
// Created by ��һ�� on 2020/5/21.
// Q461����������
//

#include "util.h"

class Solution {
public:
    // ͨ��������,�ټ�����ý�������Ʊ�ʾ��1�ĸ���
    int hammingDistance(int x, int y) {
        int difference = x ^ y;
        int result = 0;
        while (difference != 0) {
            if (difference % 2 == 1) {
                result++;
            }
            // ����Ҳ��������λ�������
            difference = difference / 2;
        }
        return result;
    }
};

