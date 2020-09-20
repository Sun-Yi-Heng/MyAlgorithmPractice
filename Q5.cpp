//
// Created by 孙一恒 on 2020/6/6.
// Q5、最长回文子串
//

#include "util.h"

class Solution {
public:
    /**
     * 方法1:笨逼判断,时间复杂度在O(N^2)和O(N ^ 3)之间,超出了时间限制
     */
    string longestPalindrome(string s) {
        int max_length = 0;
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            // 我们只需要比较可能的更长的回文子串
            for (int j = i + max_length; j < s.size(); j++) {
                if (judge(s.substr(i, j - i + 1))) {
                    max_length = j - i + 1;
                    result = s.substr(i, j - i + 1);
                }
            }
        }
        return result;
    }

    // 判断s是否是一个最长的回文子串
    bool judge(string s) {
        for (int start = 0, end = s.size() - 1; start < end; start++, end--) {
            if (s[start] != s[end]) {
                return false;
            }
        }
        return true;
    }

    /**
     * 方法2:对于长度为n的s来说,可能有2 * n - 1个点作为中心点(以每个字符作为中心/以字符和字符中间的位置作为中心)
     * 得到最长的回文子串可能是我们要求的最长回文子串,因此我们依次查找
     * 时间复杂度O(N ^ 2)(实际提交时,效率最高)
     */
    string longestPalindrome1(string s) {
        if (s.length() < 2) {
            return s;
        }
        int max_length = 1;
        int start_index = 0;
        // 枚举所有可能的中心点,然后对每个中心点进行扩散
        for (int i = 0; i <= 2 * s.length() - 1; i++) {
            int left = (i - 1) / 2;
            int right = i / 2 + 1;
            for (; left >= 0 && right < s.length(); left--, right++) {
                if (s[left] != s[right]) {
                    break;
                }
            }
            if (max_length < (right - left - 1)) {
                max_length = right - left - 1;
                start_index = left + 1;
            }
        }
        return s.substr(start_index, max_length);
    }

    /**
     * 方法3:动态规划,dp[i][j]代表从s[i]到s[j]的字符串是否为回文子串
     * 有dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j]
     * 这样,填表的过程中,我们只需要填左上三角的部分即可,且按照距离来填
     * 时间复杂度O(N ^ 2)、空间复杂度O(N ^ 2)
     */
    string longestPalindrome2(string s) {
        // 处理特殊情况
        if (s.size() <= 1) {
            return s;
        }
        int max_length = 1;
        int start_index = 0;
        bool dp[s.size()][s.size()];
        // 初始化
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                dp[i][j] = i == j;
            }
        }
        // 开始填表
        for (int gap = 1; gap < s.size(); gap++) {
            for (int i = 0; i + gap < s.size(); i++) {
                int j = i + gap;
                dp[i][j] = ((i + 1 <= j - 1) ? dp[i + 1][j - 1] : true) && s[i] == s[j];
                if (dp[i][j] && j - i + 1 > max_length) {
                    max_length = j - i + 1;
                    start_index = i;
                    // 没必要在这里直接进行截取,因为截取也消耗性能
//                    result = s.substr(i, j - i + 1);
                }
            }
        }
        return s.substr(start_index, max_length);
    }
};

