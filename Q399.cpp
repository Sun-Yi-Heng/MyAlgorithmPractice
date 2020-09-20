//
// Created by ��һ�� on 2020/5/16.
// Q399��������ֵ
//
#include "util.h"

class Solution {
public:
    /**
     * ����1:��������ͼ, Ȼ�������ת��Ϊ����ı��ʽ������������ͼ���Ƿ����һ��·��,�������ļ���������ͼ�ı߾�����
     * ���ܹ���N������,M������,����㷨��ʱ�临�Ӷ�Ӧ����O(max(N^2, MN))����
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
        // �����ڽӾ��󲢳�ʼ��
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
        // ��������ʽ��
        for (vector<string> question : queries) {
            result.push_back(solve((double*)adjacent_matrix, index, variable_index_map, question));
        }
        return result;
    }

    /**
     * ����BFS�������,
     */
    double solve(double* adjacent_matrix,int size, unordered_map<string, int>& variable_index_map, vector<string>& question) {
        string v1 = question[0];
        string v2 = question[1];
        // ���ų��������
        if (variable_index_map.find(v1) == variable_index_map.end() || variable_index_map.find(v2) == variable_index_map.end()) {
            return -1;
        }
        int index_v1 = variable_index_map.find(v1)->second;
        int index_v2 = variable_index_map.find(v2)->second;
        // ������������,һ���������й�����ȱ���,��һ����¼��ǰ������,��ɨ��Ŀ���,ֱ�ӷ��ؼ���
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
     * ����2��ʹ�ô�Ȩ�صĲ��鼯
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
        // ����������ֱ��¼���鼯�Ĺ�ϵ�ͱ���
        int father[index];
        double ratio[index];
        for (int i = 0; i < index; i++) {
            father[i] = -1;
            ratio[i] = 1;
        }
        // ���ݹ�ʽ��ͨ��union���������첢�鼯
        for (int i = 0; i < values.size(); i++) {
            string v1 = equations[i][0];
            string v2 = equations[i][1];
            int index1 = variable_index_map.find(v1)->second;
            int index2 = variable_index_map.find(v2)->second;
            my_union(index, father, ratio, index1, index2, values[i]);
        }
        // ���ݲ��鼯,ʹ��find��������ý��
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
     * ���鼯�ĺϲ�����,��index1��index2
     */
    void my_union(int size, int* father, double* ratio, int index1, int index2, double value) {
        int ancestor1 = find(size, father, index1), ancestor2 = find(size, father, index2);
        father[ancestor1] = ancestor2;
        ratio[ancestor1] = value;
    }

    /**
     * ���鼯�Ĳ��Ҳ���,���Ҵ����±�Ԫ�ص�����,��·��ѹ��
     */
    int find(int size, int* father, int index) {
        int current_index = index;
        while (father[current_index] != -1) {
            current_index = father[current_index];
        }
        return current_index;
    }

    /**
     * ���鼯�Ĳ�ѯ����(�ػ����),��ѯ�����ڵ��Ƿ����ᣬ�����,������������,������ǣ�����-1
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