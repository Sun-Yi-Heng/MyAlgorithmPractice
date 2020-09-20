//
// Created by ��һ�� on 2020/5/27.
// Q617���ϲ�������
//
#include "util.h"

class Solution {
public:
    /**
     * ����1:�ݹ鷨
     * ʱ�临�Ӷ�O(N),�����¿ռ临�Ӷ�O(N), ����NΪ�ϲ������еĽڵ�
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
