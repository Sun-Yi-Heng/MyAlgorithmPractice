//
// Created by ��һ�� on 2020/6/23.
// Q14�������ǰ׺
//
#include "util.h"

class Solution {
public:
    /**
     * ����1:�����Ƚ�
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