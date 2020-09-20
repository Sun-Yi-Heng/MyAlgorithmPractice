//
// Created by ��һ�� on 2020/6/16.
// Q8���ַ���ת������ (atoi)
//

#include "util.h"

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int i = 0, op = 1;
        // �ҵ���һ�������жϵ��ַ�
        while (i < str.size()) {
            if (str[i] != ' ') {
                break;
            } else {
                i++;
            }
        }
        if (i == str.size()) {
            return 0;
        }
        // �����ж�
        if (str[i] == '-') {
            op = -1;
            i++;
        } else if (str[i] == '+') {
            op = 1;
            i++;
        }
        // ��ֵ����,���ж�������ж���Դ��Q7
        for (; i < str.size() && str[i] >= '0' && str[i] <= '9'; i++) {
            int current = (str[i] - '0') * op;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && current > 7)) {
                return INT_MAX;
            }
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && current < -8)) {
                return INT_MIN;
            }
            result = result * 10 + current;
        }
        return result;
    }
};
