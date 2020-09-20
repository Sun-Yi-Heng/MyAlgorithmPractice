//
// Created by ��һ�� on 2020/3/29.
// Q240��������ά����
//

#include "util.h"

class Solution {
public:
    /**
     * ���ư����Ƚ�:ʱ�临�Ӷ�O(N^2), �ռ临�Ӷ�O(1),���������ʱ������
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowNum = matrix.size();
        if (rowNum == 0) {
            return false;
        }
        int columnNum = matrix[0].size();
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }

    // ����2:��������,�����Ƕ���ÿһ�н��ж�������,ʱ�临�Ӷ�ΪO(m*lgn), �ռ临�Ӷ�O(1)
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            if (binarySearch(matrix[i], target)) {
                return true;
            }
        }
        return false;
    }

    bool binarySearch(vector<int>& v, int target) {
        int start = 0;
        int end = v.size() - 1;
        while (start <= end) {
            int middle = (start + end) / 2;
            if (v[middle] < target) {
                start = middle + 1;
            } else if (v[middle] > target) {
                end = middle - 1;
            } else {
                return true;
            }
        }
        return false;
    }


    /**
     * LeetCode����3:�����ռ������
     */
    bool searchMatrix3(vector<vector<int>>& matrix, int target) {
        int rowNum = matrix.size();
        if (rowNum == 0) {
            return false;
        }
        int columnNum = matrix[0].size();
        return searchInMatrix(0, rowNum - 1, 0, columnNum - 1, matrix, target);
    }

    /**
     * �÷�������matrix����up��down��left��right���ɵı߽�����targetֵ,�ҵ�����true,�Ҳ�������false
     */
    bool searchInMatrix(int up, int down, int left, int right, vector<vector<int>>& matrix, int target) {
        // �ж������������Ƿ�Ϸ�
        if (up > down || left > right) {
            return false;
        }
        // ������ɵ�����,һ����������Ͻ�Ԫ���Ǹ�������С��,���½�Ԫ���Ǹ���������
        else if (matrix[up][left] > target || matrix[down][right] < target) {
            return false;
        }
        // ��Ҫ�ݹ����,��Ȼ������Ҫ����targetֵ�͵�ǰ��Χȷ��target����λ�ڵ��ӷ�Χ
        int midRow = up + (down - up) / 2;
        int currentColumn = left;
        while (currentColumn <= right && matrix[midRow][currentColumn] <= target) {
            if (matrix[midRow][currentColumn] == target) {
                return true;
            }
            currentColumn++;
        }
        // �ݹ�����ȷ��������½Ǻ����Ͻ�
        return searchInMatrix(midRow + 1, down, left, currentColumn - 1, matrix, target) || searchInMatrix(up, midRow - 1, currentColumn, right, matrix, target);
    }

    /**
     * leetcode����4�����ƶ�ָ��,�ų������ܵ�����,ʱ�临�Ӷ�ΪO(M + N)
     */
    bool searchMatrix4(vector<vector<int>>& matrix, int target) {
        int rowNum = matrix.size();
        if (rowNum == 0) {
            return false;
        }
        int columnNum = matrix[0].size();
        int currentRow = rowNum - 1, currentColumn = 0;
        while (currentRow >= 0 && currentColumn < columnNum) {
            if (matrix[currentRow][currentColumn] == target) {
                return true;
            } else if (matrix[currentRow][currentColumn] < target) {
                currentColumn++;
            } else {
                currentRow--;
            }
        }
        return false;
    }
};
