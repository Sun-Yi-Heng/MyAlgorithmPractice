//
// Created by ��һ�� on 2020/3/5.
// Q104����������������
//

#include <iostream>
#include <vector>
#include <queue>
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
     * ����һ:��ȡ�ݹ�ⷨ,�ǳ���,ʱ�临�Ӷ�ΪO(n),ƽ���ռ临�Ӷ�ΪO(lgn)
     */
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
        }
    }

    /**
     * ������:�����ⷨ,����ջʵ�ֶ������������������
     */
    int maxDepth1(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int max_height = 0;
        stack<TreeNode*> node_stack;
        stack<int> height_stack;
        node_stack.push(root);
        height_stack.push(0);
        while (node_stack.size() != 0) {
            TreeNode *node = node_stack.top();
            int height = height_stack.top();
            max_height = max(max_height, height);
            node_stack.pop();
            height_stack.pop();
            if (node->left != NULL) {
                node_stack.push(node->left);
                height_stack.push(height + 1);
            }
            if (node->right != NULL) {
                node_stack.push(node->right);
                height_stack.push(height + 1);
            }
        }
        return max_height;
    }
};

