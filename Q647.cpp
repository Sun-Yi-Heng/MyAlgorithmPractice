//
// Created by 孙一恒 on 2020/5/29.
// Q647、回文子串
//

#include "util.h"

class Solution {
public:
    /**
     * 判断字符串s是否为回文子串
     */
    bool judge(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }

    /**
     * 方法1:蛮力枚举所有可能的子串,并进行判断,最坏时间复杂度O(n^3)
     */
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (judge(s.substr(i, j - i + 1))) {
                    count++;
                }
            }
        }
        return count;
    }

    /**
     * 方法2:也叫中心拓展法
     * 由于回文串的中心可能是两个字母之间,也可能就是某一个字母,所以我们尝试以每一个可能的为止作为中心
     * 找出以其为中心的所有回文串即可
     * 最坏时间复杂度O(N^2)
     */
    int countSubstrings1(string s) {
        int count = 0, left, right;
        int possible_middle = 2 * s.size() - 1;
        for (int i = 0; i < possible_middle; i++) {
            if (i % 2 == 0) {
                left = i / 2;
                right = i / 2;
            } else {
                left = i / 2;
                right = i / 2 + 1;
            }
            while (left >= 0 && right < s.size()) {
                if (s[left] == s[right]) {
                    count++;
                    left--;
                    right++;
                } else {
                    break;
                }
            }
        }
        return count;
    }
};
