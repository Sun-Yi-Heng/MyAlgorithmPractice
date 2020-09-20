//
// Created by 孙一恒 on 2020/6/23.
// Q14、最长公共前缀
//
#include "util.h"

class Solution {
public:
    /**
     * 方法1:暴力比较
     */
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string result = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            for (;(j < result.size() && j < strs[i].size()) && result[j] == strs[i][j];j++) {
            }
            result = result.substr(0, j);
        }
        return result;
    }
};