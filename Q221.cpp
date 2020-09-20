//
// Created by ��һ�� on 2020/3/24.
// Q221��ѧ�罨��
//
#include "util.h"

class Solution {
public:
    /**
     * ��Ʒ���:һ�α�����������,����ÿһ��Ϊ1�ĵ�,�ҳ�������Ϊ���Ͻǵ����������
     * �ʱ�临�Ӷ�ΪO((mn)^2),�ռ临�Ӷ�O(1)  m��n�Ǿ���Ĵ�С
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
                // Ѱ���Ըö�����Ϊ���Ͻǵ����������
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
            // �ж���
            for (int row = i; row <= i + sideLength; row++) {
                if (matrix[row][j + sideLength] == '0') {
                    flag = false;
                    break;
                }
            }
            // �ж���
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
     * ��̬�滮��:����dp[i][j]��ʾ��(i,j)Ԫ����Ϊ���½ǵ���������εı߳�
     * ״̬ת�Ʒ���:dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1
     * ʱ�临�ӶȺͿռ临�ӶȾ�ΪO(mn)
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
     * �Ż���̬�滮��,ʹ�ռ临�ӶȽ��͵�O(m)
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
