//
// Created by ��һ�� on 2020/3/20.
// Q200����������
//

#include "util.h"

class Solution {
public:

    struct Node {
        int i;
        int j;
        Node(int i, int j): i(i), j(j) {}
    };

    /**
     * ��visited��ά�����¼�ڵ��Ƿ񱻷��ʹ�,
     * ����������ʱ,�ݹ��ȥ�鿴���������ҽڵ��Ƿ�Ϊ����,�����,�����ݹ齫�������춼���Ϊ���ʹ���
     * ʹ��stack���ݹ�ת��Ϊ����
     * ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O(n^2)
     */
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int row_num = grid.size();
        int column_num = grid[0].size();
        bool visited[row_num][column_num];
        int result = 0;
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < column_num; j++) {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < column_num; j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    if (grid[i][j] == '1') {
                        result++;
                        stack<Node> node_stack;
                        Node node(i, j);
                        node_stack.push(node);
                        while (node_stack.size() != 0) {
                            Node current = node_stack.top();
                            visited[current.i][current.j] = true;
                            node_stack.pop();
                            // �ж����ĸ�����Ľڵ��Ƿ�Ϊ����
                            Node nodes[]{Node(current.i - 1, current.j), Node(current.i + 1, current.j), Node(current.i, current.j - 1), Node(current.i, current.j + 1)};
                            for (Node n : nodes) {
                                // �жϺϷ����Լ����Ƿ�Ϊ����
                                if (n.i >= 0 && n.i < row_num && n.j >= 0 && n.j < column_num) {
                                    if (!visited[n.i][n.j] && grid[n.i][n.j] == '1') {
                                        node_stack.push(n);
                                    }
                                    visited[n.i][n.j] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return result;
    }

    /**
     * ����2:ʹ�ò��鼯,������������һ��ˮ����ȫ�����ӵ�һ���ڵ�
     */
    class UnionFind {
    public:
        int count; // count�����˵�ǰ�ļ��ϸ���
        int* parent; // parent�������ڼ�¼�����ڵ�ĸ��ڵ��±�
        int* rank; // rank���ڼ�¼�����ڵ������ļ��ϵĸ���
        UnionFind(int elementNum) {
            count = elementNum;
            parent = new int[elementNum];
            rank = new int[elementNum];
            for (int i = 0; i < count; i++) {
                *(parent + i) = i;
                *(rank + i) = 1;
            }
        }

        /**
         * ���Ҳ��鼯�е�i���ڵ�ĸ��ڵ�
         */
        int find(int element) {
            while (parent[element] != element) {
                int temp = element;
                element = parent[element];
                parent[temp] = parent[parent[temp]];
            }
            return element;
        }

        /**
         * ���Ӳ��鼯�е���������
         */
        void union_two_element(int element1, int element2) {
            int root1 = find(element1);
            int root2 = find(element2);

            if (root1 != root2) {
                if (rank[root1] <= rank[root2]) {
                    parent[root2] = root1;
                    rank[root1] = rank[root1] + rank[root2];
                } else {
                    parent[root1] = root2;
                    rank[root2] = rank[root1] + rank[root2];
                }
                count--;
            }
        }
    };

    int numIslands1(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int rowNum = grid.size();
        int columnNum = grid[0].size();
        UnionFind unionFind(rowNum * columnNum + 1);
        for (int i = 0; i < rowNum; i++) {
            for (int j = 0; j < columnNum; j++) {
                if (grid[i][j] == '0') {
                    unionFind.union_two_element(i * columnNum + j, rowNum * columnNum);
                } else {
                    Node nodes[]{Node(i, j + 1), Node(i + 1, j)};
                    for (Node n : nodes) {
                        if (n.i >= 0 && n.i < rowNum && n.j >= 0 && n.j < columnNum) {
                            if (grid[n.i][n.j] == '1') {
                                unionFind.union_two_element(i * columnNum + j, n.i * columnNum + n.j);
                            }
                        }
                    }
                }
            }
        }
        return unionFind.count - 1;
    }
};

