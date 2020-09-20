//
// Created by ��һ�� on 2020/2/26.
// Q85��������
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * ˼·:���Ǵ����Ͻǿ�ʼ������ά����,�����ǰԪ����1,������Ե�ǰԪ��Ϊ���Ͻǵ����ľ������
     * ��ô�ؼ���������ο��ٵ��ҵ���ĳһ������Ԫ��Ϊ���Ͻǵ������Ρ�����ʹ�õķ��������Ǳ���,����ͨ��ɨ�赽��0Ԫ�ؽ����Ż������ٱ����Ĵ�����
     */
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int area = 0;
        int row_size = matrix.size();
        int column_size = matrix[0].size();
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < column_size; j++) {
                if (matrix[i][j] == '1') {
                    // ȷ����matrix[i][j]Ԫ����Ϊ���Ͻǵ�������
                    int row_boundary = row_size;
                    int column_boundary = column_size;
                    for (int i_ = i; i_ < row_boundary; i_++) {
                        for (int j_ = j; j_ < column_boundary; j_++) {
                            if (matrix[i][j] == '0') {
                                column_boundary = j_;
                            } else {
                                area = max(area, (i_ - i + 1) * (j_ - j + 1));
                            }
                        }
                    }
                }
            }
        }
        return area;
    }
};

