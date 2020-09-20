//
// Created by 孙一恒 on 2020/5/23.
// Q538、把二叉搜索树转化为累加树
//
#include "util.h"

class Solution {
public:
    /**
     * 使用从右到左的中序遍历,即先遍历右子树再根节点再左子树(这样遍历的顺序正好是数值由大到小,只需要记录当前的结果即可）
     */
    TreeNode* convertBST(TreeNode* root) {
        int current_sum = 0;
        myOrder(root, current_sum);
        return root;
    }

    void myOrder(TreeNode* current, int& current_sum) {
        if (current == NULL) {
            return;
        }
        // 先遍历右子树
        myOrder(current->right, current_sum);
        // 遍历根节点
        current->val = current->val + current_sum;
        current_sum = current->val;
        // 最后遍历左子树
        myOrder(current->left, current_sum);
    }

    /**
     * 使用栈将上面的过程由迭代转化为递归
     */
    TreeNode* convertBST1(TreeNode* root) {
        int current_sum = 0;
        stack<TreeNode*> problem_stack;
        TreeNode* current = root;
        while (problem_stack.size() != 0 || current != NULL) {
            while (current != NULL) {
                problem_stack.push(current);
                current = current->right;
            }
            current = problem_stack.top();
            problem_stack.pop();
            current_sum += current->val;
            current->val = current_sum;
            current = current->left;
        }
        return root;
    }
};

