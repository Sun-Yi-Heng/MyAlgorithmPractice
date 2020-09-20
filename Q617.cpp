//
// Created by 孙一恒 on 2020/5/27.
// Q617、合并二叉树
//
#include "util.h"

class Solution {
public:
    /**
     * 方法1:递归法
     * 时间复杂度O(N),最坏情况下空间复杂度O(N), 其中N为合并后树中的节点
     */
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        }
        TreeNode *current = new TreeNode((t1 == NULL ? 0 : t1->val) + (t2 == NULL ? 0 : t2->val));
        current->left = mergeTrees(t1 == NULL ? NULL : t1->left, t2 == NULL ? NULL : t2->left);
        current->right = mergeTrees(t1 == NULL ? NULL : t1->right, t2 == NULL ? NULL : t2->right);
        return current;
    }

};
