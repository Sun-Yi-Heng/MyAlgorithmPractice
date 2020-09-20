//
// Created by 孙一恒 on 2020/2/15.
// Q64、最小路径和
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 不难看出这同样是一个动态规划问题,设result[m][n]数组
     * 其元素(i,j)代表从(0,0)出发,到第(i,j)个元素的最短路径,我们的目标就是求result[m-1][n-1]
     * 状态转移方程为result[i][j] = grid[i][j] + min(result[i][j-1], result[i-1][j])
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

