//
// Created by ��һ�� on 2020/3/22.
// Q207���γ̱�
//

#include "util.h"

class Solution {
public:
    /**
     * ����תΪ�ڽӾ���洢�γ̹��ɵ�ͼ,
     * Ȼ���������·���ķ���,����Ѱ��ͼ�����Ϊ0�Ľڵ㣬����ȥ����Щ�ڵ���Ϊ���ı�
     * ��ֱ��������нڵ��Ƿ񶼱����ʹ�
     * ����ʹ���ڽӾ���洢,�ʿռ临�Ӷ�ΪO(V^2),ʱ�临�Ӷ�O(V^3)
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool learned[numCourses];
        // ��ȡ�ڽӾ������洢ͼ������γ�1��ǰ�ÿγ��ǿγ�0������һ���γ�0ָ��γ�1�������,����û�б�
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
        // �����ڽӾ���,����Ѱ�����Ϊ0�Ľڵ�,���з���,Ȼ���ͼ��ɾȥ�Ӹýڵ�����ı�,ֱ���Ҳ��������Ľڵ�Ϊֹ
        int result = 0;
        while ((result = findZeroInDegree(numCourses, (int*)adjacent_matrix, learned)) != -1) {
            learned[result] = true;
            for (int i = 0; i < numCourses; i++) {
                adjacent_matrix[result][i] = 0;
            }
        }

        // ������пγ��Ƿ���ѧ��
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
     * ���Ը�Ϊʹ���ڽӱ�洢,�Ҽ���ÿ���ڵ�����,���������Ϊ0�Ľڵ���������,�������еĽڵ�һ�ε���
     * �����Ӹýڵ�����������ڵ������µ����--��ֱ������Ϊ�գ���ʱ����Ƿ����нڵ����ȶ�Ϊ0
     * ʱ�临�Ӷ�O(V + E),�ռ临�Ӷ�O(V)
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
        // �����ڽӾ���,����Ѱ�����Ϊ0�Ľڵ�,���з���,Ȼ���ͼ��ɾȥ�Ӹýڵ�����ı�,ֱ���Ҳ��������Ľڵ�Ϊֹ
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
        // ������пγ��Ƿ���ѧ��
        for (int i = 0; i < numCourses; i++) {
            if (in_degree_table[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

