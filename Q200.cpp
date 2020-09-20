//
// Created by 孙一恒 on 2020/3/20.
// Q200、岛屿数量
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
     * 用visited二维数组记录节点是否被访问过,
     * 当遇到岛屿时,递归的去查看其上下左右节点是否为岛屿,如果是,继续递归将整个岛屿都标记为访问过。
     * 使用stack将递归转化为迭代
     * 时间复杂度O(n^2),空间复杂度O(n^2)
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
                            // 判断其四个方向的节点是否为岛屿
                            Node nodes[]{Node(current.i - 1, current.j), Node(current.i + 1, current.j), Node(current.i, current.j - 1), Node(current.i, current.j + 1)};
                            for (Node n : nodes) {
                                // 判断合法性以及其是否为岛屿
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
     * 方法2:使用并查集,将岛屿连接在一起，水域则全部连接到一个节点
     */
    class UnionFind {
    public:
        int count; // count代表了当前的集合个数
        int* parent; // parent数组用于记录各个节点的父节点下标
        int* rank; // rank用于记录各个节点所属的集合的个数
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
         * 查找并查集中第i个节点的根节点
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
         * 连接并查集中的两个集合
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

