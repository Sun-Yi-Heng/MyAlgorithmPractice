//
// Created by ��һ�� on 2020/6/17.
// Q9��������
//
#include "util.h"

class Solution {
public:
    bool isPalindrome(int x) {
        // ���ڸ���,��������һ������false
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
        // ����ֻ��Ҫ�Ƚ�һ������ּ���
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
