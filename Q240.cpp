//
// Created by 孙一恒 on 2020/3/29.
// Q240、搜索二维矩阵
//

#include "util.h"

class Solution {
public:
    /**
     * 笨逼挨个比较:时间复杂度O(N^2), 空间复杂度O(1),结果超出了时间限制
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

    // 方法2:二分搜索,但是是对于每一行进行二分搜索,时间复杂度为O(m*lgn), 空间复杂度O(1)
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
     * LeetCode方法3:搜索空间的缩减
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
     * 该方法的在matrix的由up、down、left、right构成的边界搜索target值,找到返回true,找不到返回false
     */
    bool searchInMatrix(int up, int down, int left, int right, vector<vector<int>>& matrix, int target) {
        // 判断搜索的区域是否合法
        if (up > down || left > right) {
            return false;
        }
        // 根据题干的描述,一个区域的左上角元素是该区域最小的,右下角元素是该区域最大的
        else if (matrix[up][left] > target || matrix[down][right] < target) {
            return false;
        }
        // 想要递归求解,自然我们需要根据target值和当前范围确定target可能位于的子范围
        int midRow = up + (down - up) / 2;
        int currentColumn = left;
        while (currentColumn <= right && matrix[midRow][currentColumn] <= target) {
            if (matrix[midRow][currentColumn] == target) {
                return true;
            }
            currentColumn++;
        }
        // 递归搜索确定后的左下角和右上角
        return searchInMatrix(midRow + 1, down, left, currentColumn - 1, matrix, target) || searchInMatrix(up, midRow - 1, currentColumn, right, matrix, target);
    }

    /**
     * leetcode方法4：逐渐移动指针,排除不可能的区域,时间复杂度为O(M + N)
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
