//
// Created by 孙一恒 on 2020/3/8.
// Q124、二叉树中的最大路径和
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * 分治法+迭代遍历法求解
     * 将问题进行拆分,原问题的解等于对于左右子树求解子问题和计算经过当前根节点的最大路径和的求max。
     * 而merge的时间复杂度为
     */
    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return root->val;
        }
        return max(max(maxPathSum(root->left), maxPathSum(root->right)), merge(root));
    }

    // 如何计算经过根节点的连通左右子树的一条路径最长,回溯法
    int merge(TreeNode *root_node) {
        int left_length = 0;
        int right_length = 0;
        int max_path = root_node->val;
        if (root_node->left != NULL) {
            // 两个stack分别存储从根节点到遍历到的当前节点和对应的路径长度
            stack<int> path_length_stack;
            stack<TreeNode*> node_stack;
            node_stack.push(root_node->left);
            path_length_stack.push(root_node->left->val);
            left_length = DFS_maxLength(path_length_stack, node_stack);
        }
        if (root_node->right != NULL) {
            // 两个stack分别存储从根节点到遍历到的当前节点和对应的路径长度
            stack<int> path_length_stack;
            stack<TreeNode*> node_stack;
            node_stack.push(root_node->right);
            path_length_stack.push(root_node->right->val);
            right_length = DFS_maxLength(path_length_stack, node_stack);
        }
        if (left_length > 0) {
            max_path += left_length;
        }
        if (right_length > 0) {
            max_path += right_length;
        }
        return max_path;
    }

    int DFS_maxLength(stack<int> path_length_stack, stack<TreeNode*> node_stack) {
        int max_path = 0;
        while (node_stack.size() != 0) {
            TreeNode* current = node_stack.top();
            int current_length = path_length_stack.top();
            max_path = max(current_length, max_path);
            node_stack.pop();
            path_length_stack.pop();
            if (current->right != NULL) {
                node_stack.push(current->right);
                path_length_stack.push(current_length + current->right->val);
            }
            if (current->left != NULL) {
                node_stack.push(current->left);
                path_length_stack.push(current_length + current->left->val);
            }
        }
        return max_path;
    }
};

