//
// Created by 孙一恒 on 2020/6/6.
// Q6、Z字形变换
//

#include "util.h"

class Solution {
public:
    /**
     * 思路很简单:根据Z字形的规律,遍历字符串得到每一行的字符串,再把它们拼接起来即可。
     * 时间复杂度O(N), 空间复杂度O(N),其中N为字符串的长度
     */
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> row_string;
        row_string.resize(numRows, "");
        int current_row = 0;
        bool increment = true;
        for (int i = 0; i < s.size(); i++) {
            row_string[current_row] += s[i];
            if (increment) {
                current_row++;
                if (current_row == numRows - 1) {
                    increment = false;
                }
            } else {
                current_row--;
                if (current_row == 0) {
                    increment = true;
                }
            }
        }
        string result = "";
        for (int i = 0; i < row_string.size(); i++) {
            result += row_string[i];
        }
        return result;
    }
};

