//
// Created by 孙一恒 on 2020/2/10.
// Q48、旋转图像
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 观察旋转过程，发现是矩阵中4个元素一组，一次交换顺序即可得到结果，我们需要找出这4个元素坐标之间的关系
     * 我们发现(i,j)的旋转后的位置为(j, n-1-i)，根据这一规律,我们可以完成转换
     */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp[4];
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                // 开始依次进行交换
                int row = i;
                int col = j;
                int next_row = row, next_col = col;
                for (int step = 0; step < 4; step++) {
                    temp[step] = matrix[next_row][next_col];
                    int t = next_row;
                    next_row = next_col;
                    next_col = n - 1 - t;
                }
//                next_row = row, next_col = col;
                for (int step = 0; step < 4; step++) {
                    matrix[next_row][next_col] = temp[(step + 3) % 4];
                    int t = next_row;
                    next_row = next_col;
                    next_col = n - 1 - t;
                }
            }
        }
    }
};
