//
// Created by ��һ�� on 2020/5/23.
// Q538���Ѷ���������ת��Ϊ�ۼ���
//
#include "util.h"

class Solution {
public:
    /**
     * ʹ�ô��ҵ�����������,���ȱ����������ٸ��ڵ���������(����������˳����������ֵ�ɴ�С,ֻ��Ҫ��¼��ǰ�Ľ�����ɣ�
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
        // �ȱ���������
        myOrder(current->right, current_sum);
        // �������ڵ�
        current->val = current->val + current_sum;
        current_sum = current->val;
        // ������������
        myOrder(current->left, current_sum);
    }

    /**
     * ʹ��ջ������Ĺ����ɵ���ת��Ϊ�ݹ�
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

