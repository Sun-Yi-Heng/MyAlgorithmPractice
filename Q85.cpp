//
// Created by 孙一恒 on 2020/2/26.
// Q85、最大矩形
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * 思路:我们从左上角开始遍历二维数组,如果当前元素是1,则计算以当前元素为坐上角的最大的矩形面积
     * 那么关键就在于如何快速的找到以某一个给定元素为左上角的最大矩形。这里使用的方法依旧是遍历,但是通过扫描到的0元素进行优化来减少遍历的次数。
     */
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int area = 0;
        int row_size = matrix.size();
        int column_size = matrix[0].size();
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < column_size; j++) {
                if (matrix[i][j] == '1') {
                    // 确定以matrix[i][j]元素作为左上角的最大矩形
                    int row_boundary = row_size;
                    int column_boundary = column_size;
                    for (int i_ = i; i_ < row_boundary; i_++) {
                        for (int j_ = j; j_ < column_boundary; j_++) {
                            if (matrix[i][j] == '0') {
                                column_boundary = j_;
                            } else {
                                area = max(area, (i_ - i + 1) * (j_ - j + 1));
                            }
                        }
                    }
                }
            }
        }
        return area;
    }
};

