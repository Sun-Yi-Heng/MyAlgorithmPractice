//
// Created by ��һ�� on 2020/3/24.
// Q226����ת������
//
#include "util.h"

class Solution {
public:
    /**
     * ���ȳ��Եݹ��㷨,ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(lgn)
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
     * ���Ե����㷨
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
            // �������ҽڵ�
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
 * ���Ե����㷨
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
            // �������ҽڵ�
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
