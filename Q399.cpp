//
// Created by 孙一恒 on 2020/5/16.
// Q399、除法求值
//
#include "util.h"

class Solution {
public:
    /**
     * 方法1:构建有向图, 然后问题就转变为待求的表达式两变量在有向图中是否存在一条路径,具体结果的计算由有向图的边决定。
     * 设总共有N个变量,M个问题,则该算法的时间复杂度应该在O(max(N^2, MN))左右
     */
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> result;
        unordered_map<string, int> variable_index_map;
        int index = 0;
        for (auto eq : equations) {
            for (string variable : eq) {
                auto find_result = variable_index_map.find(variable);
                if (find_result == variable_index_map.end()) {
                    variable_index_map[variable] = index++;
                }
            }
        }
        // 声明邻接矩阵并初始化
        double adjacent_matrix[index][index];
        for (int i = 0; i < index; i++) {
            for (int j = 0; j < index; j++) {
                if (i == j) {
                    adjacent_matrix[i][j] = 1;
                } else {
                    adjacent_matrix[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < equations.size(); i++) {
            string v1 = equations[i][0];
            string v2 = equations[i][1];
            int index_v1 = variable_index_map.find(v1)->second;
            int index_v2 = variable_index_map.find(v2)->second;
            adjacent_matrix[index_v1][index_v2] = values[i];
            adjacent_matrix[index_v2][index_v1] = 1 / values[i];
        }
        // 求解给出的式子
        for (vector<string> question : queries) {
            result.push_back(solve((double*)adjacent_matrix, index, variable_index_map, question));
        }
        return result;
    }

    /**
     * 利用BFS求解问题,
     */
    double solve(double* adjacent_matrix,int size, unordered_map<string, int>& variable_index_map, vector<string>& question) {
        string v1 = question[0];
        string v2 = question[1];
        // 先排除特殊情况
        if (variable_index_map.find(v1) == variable_index_map.end() || variable_index_map.find(v2) == variable_index_map.end()) {
            return -1;
        }
        int index_v1 = variable_index_map.find(v1)->second;
        int index_v2 = variable_index_map.find(v2)->second;
        // 申请两个队列,一个用来进行广度优先遍历,另一个记录当前计算结果,当扫到目标点,直接返回即可
        queue<double > result;
        queue<int> index_queue;
        bool visited[size];
        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }
        index_queue.push(index_v1);
        result.push(1);
        while (index_queue.size() != 0) {
            int current_index = index_queue.front();
            double current_result = result.front();
            if (current_index == index_v2) {
                return current_result;
            }
            index_queue.pop();
            result.pop();
            visited[current_index] = true;
            for (int i = 0; i < size; i++) {
                if (!visited[i] && *(adjacent_matrix + current_index * size + i) > 0) {
                    index_queue.push(i);
                    result.push(current_result * *(adjacent_matrix + current_index * size + i));
                }
            }
        }
        return -1;
    }

    /**
     * 方法2、使用带权重的并查集
     */
    vector<double> calcEquation1(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> result;
        unordered_map<string, int> variable_index_map;
        int index = 0;
        for (auto eq : equations) {
            for (string variable : eq) {
                auto find_result = variable_index_map.find(variable);
                if (find_result == variable_index_map.end()) {
                    variable_index_map[variable] = index++;
                }
            }
        }
        // 用两个数组分别记录并查集的关系和比率
        int father[index];
        double ratio[index];
        for (int i = 0; i < index; i++) {
            father[i] = -1;
            ratio[i] = 1;
        }
        // 根据公式，通过union操作，构造并查集
        for (int i = 0; i < values.size(); i++) {
            string v1 = equations[i][0];
            string v2 = equations[i][1];
            int index1 = variable_index_map.find(v1)->second;
            int index2 = variable_index_map.find(v2)->second;
            my_union(index, father, ratio, index1, index2, values[i]);
        }
        // 根据并查集,使用find操作，获得结果
        for (vector<string> question : queries) {
            string v1 = question[0];
            string v2 = question[1];
            if (variable_index_map.find(v1) == variable_index_map.end() || variable_index_map.find(v2) == variable_index_map.end()) {
                result.push_back(-1);
            } else {
                int index1 = variable_index_map.find(v1)->second;
                int index2 = variable_index_map.find(v2)->second;
                result.push_back(get_result(index, father, ratio, index1, index2));
            }
        }
        return result;
    }

    /**
     * 并查集的合并操作,将index1和index2
     */
    void my_union(int size, int* father, double* ratio, int index1, int index2, double value) {
        int ancestor1 = find(size, father, index1), ancestor2 = find(size, father, index2);
        father[ancestor1] = ancestor2;
        ratio[ancestor1] = value;
    }

    /**
     * 并查集的查找操作,查找传入下标元素的祖先,带路径压缩
     */
    int find(int size, int* father, int index) {
        int current_index = index;
        while (father[current_index] != -1) {
            current_index = father[current_index];
        }
        return current_index;
    }

    /**
     * 并查集的查询操作(特化后的),查询两个节点是否连结，如果是,返回其相除结果,如果不是，返回-1
     */
     double get_result(int size, int* father, double* ratio, int index1, int index2) {
         double temp1 = 1, temp2 = 1;
         while (father[index1] != -1) {
             temp1 = temp1 * ratio[index1];
             index1 = father[index1];
         }
        while (father[index2] != -1) {
            temp2 = temp2 * ratio[index2];
            index2 = father[index2];
        }
         return temp1 / temp2;
     }
};