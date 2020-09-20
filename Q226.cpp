//
// Created by 孙一恒 on 2020/3/24.
// Q226、反转二叉树
//
#include "util.h"

class Solution {
public:
    /**
     * 首先尝试递归算法,时间复杂度O(n),空间复杂度O(lgn)
     */
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }

    /**
     * 尝试迭代算法
     */
    TreeNode* invertTree1(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (node_stack.size() != 0) {
            TreeNode *current = node_stack.top();
            node_stack.pop();
            // 交换左右节点
            TreeNode* temp = current->left;
            current->left = current->right;
            current->right = temp;
            if (current->left != NULL) {
                node_stack.push(current->left);
            }
            if (current->right != NULL) {
                node_stack.push(current->right);
            }
        }
        return root;
    }

    /**
 * 尝试迭代算法
 */
    TreeNode* invertTree2(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        queue<TreeNode*> node_stack;
        node_stack.push(root);
        while (node_stack.size() != 0) {
            TreeNode *current = node_stack.front();
            node_stack.pop();
            // 交换左右节点
            TreeNode* temp = current->left;
            current->left = current->right;
            current->right = temp;
            if (current->left != NULL) {
                node_stack.push(current->left);
            }
            if (current->right != NULL) {
                node_stack.push(current->right);
            }
        }
        return root;
    }
};
