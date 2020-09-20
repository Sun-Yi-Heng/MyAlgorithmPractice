//
// Created by 孙一恒 on 2020/4/30.
// Q338、比特位计数
//
#include "util.h"

class Solution {
public:
    /**
     * 方法一:通过辗转相除法确定每个数的二进制表示有多少个1,时间复杂度O(nlgn)
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
     * 结合我们对于二进制的了解,可以发现后面数的低位的运算过程就是对前面数的重复
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
     * 方法3:
     * 利用数字n和数字n-1进行位运算与操作，得到的结果是数字n最末尾1变成0的结果,重复这个过程，直到数字n变成0
     * 循环的次数就是数字n的二进制表示中1的个数
     * 时间复杂度可以认为是O(n),也可以认为是O(nlgn),与方法1比较速度更快
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
