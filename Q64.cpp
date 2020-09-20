//
// Created by ��һ�� on 2020/2/15.
// Q64����С·����
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * ���ѿ�����ͬ����һ����̬�滮����,��result[m][n]����
     * ��Ԫ��(i,j)�����(0,0)����,����(i,j)��Ԫ�ص����·��,���ǵ�Ŀ�������result[m-1][n-1]
     * ״̬ת�Ʒ���Ϊresult[i][j] = grid[i][j] + min(result[i][j-1], result[i-1][j])
     */
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int result[m][n];
        int above;
        int left;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                above = (i - 1) >= 0 ? result[i - 1][j] : INT_MAX;
                left = (j - 1) >= 0 ? result[i][j - 1] : INT_MAX;
                if (above == INT_MAX && left == INT_MAX) {
                    result[i][j] = grid[i][j];
                } else {
                    result[i][j] = min(above, left) + grid[i][j];
                }
            }
        }
        return result[m - 1][n - 1];
    }
};

