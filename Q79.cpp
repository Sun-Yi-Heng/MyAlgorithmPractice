//
// Created by ��һ�� on 2020/2/22.
// Q79����������
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int row_num;
    int column_num;
    /**
     * ����ͨ�����ݷ����
     */
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) {
            return true;
        }
        row_num = board.size();
        column_num = board[0].size();
        bool visit[row_num][column_num];
        // ��ʼ��visit����
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < column_num; j++) {
                visit[i][j] = false;
            }
        }
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < column_num; j++) {
                if (visit[i][j] == word.at(0)) {
                    if (solve(row_num, column_num, i, j, (bool *)visit, word, 0, board)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    //i, j����һ��ƥ���ַ���λ��,visit�洢Ŀǰ�Ѿ�ʹ�ù���λ��,��position���ǵ�ǰ�Ѿ�ƥ�䵽��λ��
    bool solve(int row, int column, int i, int j, bool* visit, string word, int position, vector<vector<char>>& board) {
        if (position == word.size() - 1) {
            return true;
        }
        char left = (j - 1 >= 0 && !visit[i * column + j - 1]) ? board[i][j - 1] : '*';
        char right = (j + 1 < column_num && !visit[i * column + j + 1]) ? board[i][j + 1] : '*';
        char above = (i - 1 >= 0 && !visit[(i - 1) * column + j]) ? board[i - 1][j] : '*';
        char below = (i + 1 < row_num && !visit[(i + 1) * column + j]) ? board[i + 1][j] : '*';
//        bool new_visit[row][column];
        if (above == word[position + 1]) {
//            memcpy(new_visit, visit, sizeof(new_visit));
//            new_visit[i - 1][j] = true;
            visit[(i - 1) * column + j] = true;
            if (solve(row, column, i - 1, j, (bool *)visit, word, position + 1, board)) {
                return true;
            }
        }
        if (below == word[position + 1]) {
//            memcpy(new_visit, visit, sizeof(new_visit));
//            new_visit[i + 1][j] = true;
            visit[(i + 1) * column + j] = true;
            if (solve(row, column, i + 1, j, (bool *)visit, word, position + 1, board)) {
                return true;
            }
        }
        if (left == word[position + 1]) {
//            memcpy(new_visit, visit, sizeof(new_visit));
//            new_visit[i][j - 1] = true;
            visit[i * column + j - 1] = true;
            if (solve(row, column, i, j - 1, (bool *)visit, word, position + 1, board)) {
                return true;
            }
        }
        if (right == word[position + 1]) {
//            memcpy(new_visit, visit, sizeof(new_visit));
//            new_visit[i][j + 1] = true;
            visit[i * column + j + 1] = true;
            if (solve(row, column, i, j + 1, (bool *)visit, word, position + 1, board)) {
                return true;
            }
        }
        return false;
    }
};
