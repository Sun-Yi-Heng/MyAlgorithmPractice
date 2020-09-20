//
// Created by ��һ�� on 2020/6/16.
// Q7��������ת
//

#include "util.h"

class Solution {
public:
    /**
     * ����ֱ�ӽ������㼴��,����Ҫ����ջ
     */
    int reverse(int x) {
        int op = 1;
        int result = 0;
        while (x != 0) {
            int last = x % 10;
            x /= 10;
            // ����������ж��������ĺ���
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && last > 7)) {
                return 0;
            }
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && last < -8)) {
                return 0;
            }
            result = result * 10 + x;
        }
        return result;
    }
};

