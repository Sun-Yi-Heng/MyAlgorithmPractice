//
// Created by ��һ�� on 2020/3/3.
// Q98����֤����������
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * �ݹ�ⷨ,��Ϊ���ڶ���������,���������ϵ�ȫ���ڵ�Ӧ��ȫ��С�ڸ��ڵ�,����ֻ�Ǹ��ڵ�����ӽڵ�,
     * ������ͬ��,������������½�����������
     * ˼��,��û�а취��ʹ��INT_MAX��INT_MIN?
     * @return
     */
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            return recursive(root, LONG_MAX, LONG_MIN);
        }
    }

    bool recursive(TreeNode* root, long up_bound, long low_bound) {
        if (root->val >= up_bound || root->val <= low_bound) {
            return false;
        }
        bool left = true, right = true;
        if (root->left != NULL) {
            left = recursive(root->left, root->val, low_bound);
        }
        if (root->right != NULL) {
            right = recursive(root->right, up_bound, root->val);
        }
        return left && right;
    }

    /**
     * ���õ����ⷨ,��������֪�����ڶ���������,����������õ��Ľ������������,��������ת��Ϊ��ε�����ɶԶ��������������
     * ���ֵ������������ʼ�뵽�ķ���,���Ǹ÷����ƻ���ԭ�е����Ľṹ
     */
    bool isValidBST1(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        long current = LONG_MIN, previous = LONG_MIN;
        stack<TreeNode*> s;
        while (s.size() != 0) {
            TreeNode* top = s.top();
            if (top->left != NULL) {
                s.push(top->left);
                top->left = NULL;
            } else {
                s.pop();
                current = top->val;
                if (current <= previous) {
                    return false;
                }
                previous = current;
                if (top->right != NULL) {
                    s.push(top->right);
                }
            }
        }
        return true;
    }

    /**
     * �������������������2�����ı����Ľṹ
     */
    bool isValidBST2(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        long current = LONG_MIN, previous = LONG_MIN;
        stack<TreeNode*> s;
        TreeNode* currNode = root;
        while (currNode != NULL || s.size() != 0) {
            while (currNode != NULL) {
                s.push(currNode);
                currNode = currNode->left;
            }
            currNode = s.top();
            s.pop();
            current = currNode->val;
            if (previous >= current) {
                return false;
            }
            previous = current;
            currNode = currNode->right;
        }
        return true;
    }

    /**
     * ת��˼·,���������������,�������õ����ķ������
     * @param root
     * @return
     */
    bool isValidBST3(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        stack<TreeNode*> s;
        stack<long> up_stack;
        stack<long> down_stack;
        helper(root, LONG_MIN, LONG_MAX, s, down_stack, up_stack);
        while (s.size() != 0) {
            TreeNode* current = s.top();
            long up = up_stack.top();
            long down = down_stack.top();
            s.pop();
            up_stack.pop();
            down_stack.pop();
            if (current->val <= down || current->val >= up) {
                return false;
            } else {
                if (current->left != NULL) {
                    helper(current->left, down, current->val, s, down_stack, up_stack);
                }
                if (current->right != NULL) {
                    helper(root, current->val, up, s, down_stack, up_stack);
                }
            }
        }
        return true;
    }

    void helper(TreeNode* t, long d, long u, stack<TreeNode*>& s, stack<long>& down, stack<long>& upper) {
        s.push(t);
        down.push(d);
        upper.push(u);
    }
};