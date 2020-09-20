//
// Created by 孙一恒 on 2020/3/24.
// Q221、学风建设
//
#include "util.h"

class Solution {
public:
    /**
     * 最笨逼方法:一次遍历整个矩阵,对于每一个为1的点,找出以其作为左上角的最大正方形
     * 最坏时间复杂度为O((mn)^2),空间复杂度O(1)  m、n是矩阵的大小
     */
    int maximalSquare(vector<vector<char>>& matrix) {
        int area = 0;
        int rowNum = matrix.size();
        if (rowNum == 0) {
            return area;
        }
        int columnNum = matrix[0].size();
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                // 寻找以该顶点作为左上角的最大正方形
                if (matrix[i][j] == '1') {
                    area = max(area, getAreaLength(i, j, matrix, rowNum, columnNum));
                }
            }
        }
        return area;
    }

    int getAreaLength(int i, int j, vector<vector<char>>& matrix, int rowNum, int columnNum) {
        int sideLength = 1;
        bool flag = true;
        while (i + sideLength < rowNum && j + sideLength < columnNum && flag) {
            // 判断列
            for (int row = i; row <= i + sideLength; row++) {
                if (matrix[row][j + sideLength] == '0') {
                    flag = false;
                    break;
                }
            }
            // 判断行
            for (int column = j; column <= j + sideLength; column++) {
                if (matrix[i + sideLength][column] == '0') {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                sideLength++;
            }
        }
        return sideLength * sideLength;
    }

    /**
     * 动态规划法:对于dp[i][j]表示以(i,j)元素作为右下角的最大正方形的边长
     * 状态转移方程:dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1
     * 时间复杂度和空间复杂度均为O(mn)
     */
    int maximalSquare1(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int maxLength = 0;
        int rowNum = matrix.size();
        int columnNum = matrix[0].size();
        int dp[rowNum][columnNum];
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                if (matrix[i][j] == '1') {
                    int left = (j - 1) < 0 ? 0 : dp[i][j - 1];
                    int top = (i - 1) < 0 ? 0 : dp[i - 1][j];
                    int left_top = (j - 1) < 0 || (i - 1) < 0 ? 0 : dp[i - 1][j - 1];
                    dp[i][j] = min(left, min(top, left_top)) + 1;
                    maxLength = max(maxLength, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return maxLength * maxLength;
    }

    /**
     * 优化动态规划法,使空间复杂度降低到O(m)
     * @param matrix
     * @return
     */
    int maximalSquare2(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int maxLength = 0;
        int rowNum = matrix.size();
        int columnNum = matrix[0].size();
        int dp[columnNum];
        int prev = 0;
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                if (matrix[i][j] == '1') {
                    int left = (j - 1) < 0 ? 0 : dp[j - 1];
                    int top = (i - 1) < 0 ? 0 : dp[j];
                    int left_top = prev;
                    prev = dp[j];
                    dp[j] = min(left, min(top, left_top)) + 1;
                    maxLength = max(maxLength, dp[j]);
                } else {
                    dp[j] = 0;
                }
            }
        }
        return maxLength * maxLength;
    }
};
