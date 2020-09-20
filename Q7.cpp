//
// Created by 孙一恒 on 2020/6/16.
// Q7、整数反转
//

#include "util.h"

class Solution {
public:
    /**
     * 我们直接进行运算即可,不需要辅助栈
     */
    int reverse(int x) {
        int op = 1;
        int result = 0;
        while (x != 0) {
            int last = x % 10;
            x /= 10;
            // 这里溢出的判断是这道题的核心
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

