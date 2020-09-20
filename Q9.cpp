//
// Created by 孙一恒 on 2020/6/17.
// Q9、回文数
//
#include "util.h"

class Solution {
public:
    bool isPalindrome(int x) {
        // 对于负数,按照题意一定返回false
        if (x < 0) {
            return false;
        }
        vector<int> num;
        while (x != 0) {
            int current = x % 10;
            x = x / 10;
            num.push_back(current);
        }
        for (int i = 0; i < num.size() / 2; i++) {
            if (num[i] != num[num.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    bool isPalindrome1(int x) {
        // 我们只需要比较一半的数字即可
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        int revertNum = 0;
        while (x > revertNum) {
            int current = x % 10;
            x = x / 10;
            revertNum = revertNum * 10 + current;
        }
        return revertNum == x || x == revertNum / 10;
    }
};
