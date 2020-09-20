//
// Created by 孙一恒 on 2020/3/5.
// Q104、二叉树的最大深度
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
     * 方法一:采取递归解法,非常简单,时间复杂度为O(n),平均空间复杂度为O(lgn)
     */
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
        }
    }

    /**
     * 方法二:迭代解法,利用栈实现对树进行深度优先搜索
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

