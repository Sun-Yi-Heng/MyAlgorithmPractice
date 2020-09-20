//
// Created by ��һ�� on 2020/2/15.
// Q62����ͬ·��
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * ��Ӧ����һ����̬�滮����,״̬ת�Ʒ���Ϊresult[i][j] = result[i+1][j] + result[j][i+1]
     * ʱ�临�Ӷ�ΪO(m * n),�ռ临�Ӷ�ҲΪO(m * n)
     * @return
     */
    int uniquePaths(int m, int n) {
        int result[m][n]; // �±�(i, j)�����Ŵ�λ��(m - 1 - i,n - 1 - j)����λ��(m - 1,n - 1)��·������
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
