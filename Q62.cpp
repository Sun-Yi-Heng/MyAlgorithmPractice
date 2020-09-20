//
// Created by 孙一恒 on 2020/2/15.
// Q62、不同路径
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 这应该是一个动态规划问题,状态转移方程为result[i][j] = result[i+1][j] + result[j][i+1]
     * 时间复杂度为O(m * n),空间复杂度也为O(m * n)
     * @return
     */
    int uniquePaths(int m, int n) {
        int result[m][n]; // 下标(i, j)代表着从位置(m - 1 - i,n - 1 - j)到达位置(m - 1,n - 1)的路线数量
        result[m - 1][n - 1] = 1;
        int bottom;
        int right;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >=0 ;j--) {
                if (i != m - 1 || j != n - 1) {
                    bottom = (j + 1) > (n - 1) ? 0 : result[i][j + 1];
                    right = (i + 1) > (m - 1) ? 0 : result[i + 1][j];
                    result[i][j] = bottom + right;
                }
            }
        }
        return result[0][0];
    }
};

void test_method(int row, int col, int* test) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << *(test + i * col + j) << endl;
        }
    }
}

//int main() {
//    int test[2][3] = {{1, 2, 3}, {4, 5, 6}};
//    cout << sizeof(test) << endl;
//    for (int i = 0; i < 10; i++) {
//        cout << test + i << endl;
//    }
//    test_method(2, 3, (int *)test);
//}
