//
// Created by ��һ�� on 2020/2/10.
// Q48����תͼ��
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * �۲���ת���̣������Ǿ�����4��Ԫ��һ�飬һ�ν���˳�򼴿ɵõ������������Ҫ�ҳ���4��Ԫ������֮��Ĺ�ϵ
     * ���Ƿ���(i,j)����ת���λ��Ϊ(j, n-1-i)��������һ����,���ǿ������ת��
     */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp[4];
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                // ��ʼ���ν��н���
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
