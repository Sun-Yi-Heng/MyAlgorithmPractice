//
// Created by 孙一恒 on 2020/3/22.
// Q207、课程表
//

#include "util.h"

class Solution {
public:
    /**
     * 首先转为邻接矩阵存储课程构成的图,
     * 然后根据拓扑路径的方法,不断寻找图中入度为0的节点，并消去以哪些节点作为起点的边
     * 看直到最后，所有节点是否都被访问过
     * 由于使用邻接矩阵存储,故空间复杂度为O(V^2),时间复杂度O(V^3)
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool learned[numCourses];
        // 采取邻接矩阵来存储图，如果课程1到前置课程是课程0，则有一条课程0指向课程1的有向边,否则没有边
        int adjacent_matrix[numCourses][numCourses];
        for (int i = 0; i < numCourses; i++) {
            learned[i] = false;
            for (int j = 0; j < numCourses; j++) {
                adjacent_matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            for (int j = 0; j < prerequisites[i].size() - 1; j++) {
                adjacent_matrix[prerequisites[i][j + 1]][prerequisites[i][j]] = 1;
            }
        }
        // 根据邻接矩阵,不断寻找入度为0的节点,进行访问,然后从图中删去从该节点出发的边,直到找不到这样的节点为止
        int result = 0;
        while ((result = findZeroInDegree(numCourses, (int*)adjacent_matrix, learned)) != -1) {
            learned[result] = true;
            for (int i = 0; i < numCourses; i++) {
                adjacent_matrix[result][i] = 0;
            }
        }

        // 检查所有课程是否都已学过
        for (int i = 0; i < numCourses; i++) {
            if (!learned[i]) {
                return false;
            }
        }
        return true;
    }

    int findZeroInDegree(int numCourses, int* adjacent_matrix,  bool *learned) {
        for (int i = 0; i < numCourses; i++) {
            bool flag = true;
            for (int j = 0; j < numCourses; j++) {
                if (*(adjacent_matrix + j * numCourses + i) != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag && !learned[i]) {
                return i;
            }
        }
        return -1;
    }

    struct Node {
        int nodeIndex;
        Node* next;
        Node(int nodeIndex): nodeIndex(nodeIndex), next(NULL){}
        Node():nodeIndex(-1), next(NULL){}
    };

    /**
     * 尝试改为使用邻接表存储,且计算每个节点的入度,将所有入度为0的节点放入队列中,将队列中的节点一次弹出
     * 并将从该节点出发到其他节点所导致的入度--，直到队列为空，此时检查是否所有节点的入度都为0
     * 时间复杂度O(V + E),空间复杂度O(V)
     */
    bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
        Node adjacency_list[numCourses];
        int in_degree_table[numCourses];
        for (int i = 0; i < numCourses; i++) {
            in_degree_table[i] = 0;
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            for (int j = 0; j < prerequisites[i].size() - 1; j++) {
                Node* new_node = new Node(prerequisites[i][j]);
                new_node->next = adjacency_list[prerequisites[i][j + 1]].next;
                adjacency_list[prerequisites[i][j + 1]].next = new_node;
                in_degree_table[prerequisites[i][j]]++;
            }
        }
        // 根据邻接矩阵,不断寻找入度为0的节点,进行访问,然后从图中删去从该节点出发的边,直到找不到这样的节点为止
        int result = 0;
        queue<int> zero_in_degree_queue;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree_table[i] == 0) {
                zero_in_degree_queue.push(i);
            }
        }
        while (zero_in_degree_queue.size() != 0) {
            int current_node = zero_in_degree_queue.front();
            zero_in_degree_queue.pop();
            Node *to_node = adjacency_list[current_node].next;
            while (to_node != NULL) {
                in_degree_table[to_node->nodeIndex]--;
                if (in_degree_table[to_node->nodeIndex] == 0) {
                    zero_in_degree_queue.push(to_node->nodeIndex);
                }
                to_node = to_node->next;
            }
        }
        // 检查所有课程是否都已学过
        for (int i = 0; i < numCourses; i++) {
            if (in_degree_table[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

