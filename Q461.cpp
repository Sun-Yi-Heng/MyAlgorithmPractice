//
// Created by 孙一恒 on 2020/5/21.
// Q461、汉明距离
//

#include "util.h"

class Solution {
public:
    // 通过异或操作,再计算求得结果二进制表示中1的个数
    int hammingDistance(int x, int y) {
        int difference = x ^ y;
        int result = 0;
        while (difference != 0) {
            if (difference % 2 == 1) {
                result++;
            }
            // 这里也可以用移位操作替代
            difference = difference / 2;
        }
        return result;
    }
};

