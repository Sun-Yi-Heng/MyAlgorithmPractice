//
// Created by 孙一恒 on 2020/6/9.
// Q10、正则表达式匹配
//
#include "util.h"

class Solution {
public:
    /**
     * 方法1:按照正则表达式进行比较,如果遇到*的话,就枚举所有的可能并交给递归处理
     * 算法的时间复杂度主要取决于*,在LeetCode中表现较差
     */
    bool isMatch(string s, string p) {
        // 开始进行比较
        int current = 0;
        // 我们主要需要处理的是"*"
        while (p[current + 1] != '*' && current < p.length() && current < s.length()) {
            if (p[current] == s[current] || p[current] == '.') {
                current++;
            } else {
                return false;
            }
        }
        // 如果当前是因为current超过了字符串范围而跳出循环的
        if (current >= p.length() || current >= s.length()) {
            // 由于对于pattern存在current虽然没有到尽头,但是仍然可以比较完的情况(即存在*),这里对这种情况做处理
            int p_current = current;
            if (current < p.length()) {
                while (p_current + 1 < p.length() && p[p_current + 1] == '*') {
                    p_current += 2;
                }
            }
            return p_current == p.length() && current == s.length();
        }
            // current是因为p[current + 1] = '*' 而跳出的,且还没有比较到末尾
        else {
            // 使得当前的*匹配所有可能数量的s(从0开始)
            // 匹配0次
            if (isMatch(s.substr(current), p.substr(current + 2))) {
                return true;
            }
            // 匹配其他可能的次数
            for (int i = current; i < s.length() && (s[i] == p[current] || p[current] == '.'); i++) {
                if (isMatch(s.substr(i + 1), p.substr(current + 2))) {
                    return true;
                }
            }
            // 都不行的话,返回false
            return false;
        }
    }

    /**
     * 动态规划法:状态dp[i][j]代表s[0:i]和p[0:j]是否匹配,根据已有状态求新的状态
     * 时间复杂度和空间复杂度均为O(M*N),M和N分别是字符串s和p的长度
     */
    bool isMatch1(string s, string p) {
        s = " " + s;
        p = " " + p;
        bool dp[s.length() + 1][p.length() + 1];
        memset(dp, false, (s.length() + 1) * (p.length() + 1));
        dp[0][0] = true;
        for (int i = 1; i < s.length(); i++) {
            for (int j = 1; j < p.length(); j++) {
                // 情况1
                if (s[i] == p[j] || p[j] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j] == '*') {
                    if (p[j - 1] == s[i] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                    } else {
                        dp[i][j] = (j - 2 >= 0) ? dp[i][j - 2] : false;
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};
