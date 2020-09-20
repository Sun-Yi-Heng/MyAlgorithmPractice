//
// Created by ��һ�� on 2020/2/29.
// Q94�����������������
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
     * ����1:��ͳ�ĵݹ鷨
     * @param root
     * @return
     */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        recursive(root, result);
        return result;
    }

    void recursive(TreeNode* currentNode, vector<int>& v) {
        if (currentNode == NULL) {
            return;
        } else {
            recursive(currentNode->left, v);
            v.push_back(currentNode->val);
            recursive(currentNode->right, v);
        }
    }

    /**
     * ����2:��ȡ������
     */
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        stack<TreeNode*> s;
        s.push(root);
        while (s.size() != 0) {
            TreeNode *top = s.top();
            if (top->left != NULL) {
                s.push(top->left);
                top->left = NULL;
            } else {
                result.push_back(top->val);
                s.pop();
                if (top->right != NULL) {
                    s.push(top->right);
                }
            }
        }
        return result;
    }
};
