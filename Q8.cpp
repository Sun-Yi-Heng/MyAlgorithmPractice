//
// Created by 孙一恒 on 2020/6/16.
// Q8、字符串转换整数 (atoi)
//

#include "util.h"

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int i = 0, op = 1;
        // 找到第一个可以判断的字符
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
        // 符号判断
        if (str[i] == '-') {
            op = -1;
            i++;
        } else if (str[i] == '+') {
            op = 1;
            i++;
        }
        // 数值计算,其中对溢出的判断来源于Q7
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
