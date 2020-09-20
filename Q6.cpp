//
// Created by ��һ�� on 2020/6/6.
// Q6��Z���α任
//

#include "util.h"

class Solution {
public:
    /**
     * ˼·�ܼ�:����Z���εĹ���,�����ַ����õ�ÿһ�е��ַ���,�ٰ�����ƴ���������ɡ�
     * ʱ�临�Ӷ�O(N), �ռ临�Ӷ�O(N),����NΪ�ַ����ĳ���
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

