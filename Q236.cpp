//
// Created by ��һ�� on 2020/3/25.
// Q236���������������������
//

#include "util.h"

class Solution {
public:
    TreeNode* ancestor = NULL;
    bool set = false;
    /**
     * ����1:
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findTwoNode(root, p, q);
        return ancestor;
    }

    /**
     * �ݹ鷨���,�൱���ڶ������еݹ�Ĳ��������ڵ�,���ҽ���һ�ο��Բ��ҵ�p��q�ĸ��ڵ�����Ϊ��������Ľ��
     * �������ڵݹ���ջ�ṹ,����ʱ��һ������Ҫ��Ľڵ���������������
     * ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(lgn)
     */
    int findTwoNode(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return 0;
        }
        int left_result = findTwoNode(root->left, p, q);
        int right_result = findTwoNode(root->right, p, q);
        int result = (root == p) + (root == q) + left_result + right_result;
        if (result == 2 && ancestor != NULL) {
            ancestor = root;
        }
        return result;
    }

    /**
     * �����㷨,����ջDFS������,������ڵ�Ͷ�Ӧ���ڵ��ӳ���ϵ,ֱ���ҵ�����Ҫ���ҽڵ�Ϊֹ��
     * ֮���ü��ϱ�������һ�����ҽڵ�����и��׽ڵ�,Ȼ��ʼ����һ���ڵ�ĸ��׽ڵ�������ϱ���,
     * �����������һ���ڵ�ĸ��׽ڵ㼯��ʱ,�ýڵ㼴Ϊ����
     * ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(N)
     */
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return root;
        }
        unordered_map<TreeNode*, TreeNode*> son_parent_map;
        son_parent_map[root] = NULL;
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (son_parent_map.find(p) == son_parent_map.end() || son_parent_map.find(q) == son_parent_map.end()) {
            TreeNode *current = node_stack.top();
            node_stack.pop();
            if (current->right != NULL) {
                son_parent_map[current->right] = current;
                node_stack.push(current->right);
            }
            if (current->left != NULL) {
                son_parent_map[current->left] = current;
                node_stack.push(current->left);
            }
        }
        unordered_set<TreeNode*> p_parent;
        TreeNode* current = p;
        p_parent.insert(current);
        while (son_parent_map.find(current)->second != NULL) {
            current = son_parent_map.find(current)->second;
            p_parent.insert(current);
        }
        current = q;
        while (p_parent.find(current) == p_parent.end()) {
            current = son_parent_map.find(current)->second;
        }
        return current;
    }
};

