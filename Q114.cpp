//
// Created by 孙一恒 on 2020/1/30.
// 二叉树原地展开为链表
//
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 方法1:观察给出的示例可以看出,排序后的树是按照先根遍历的顺序排列的，所以我们先进行一次先根遍历，然后一次连接即可。
 * 时间复杂度:O(n),空间复杂度O(n)
 */
vector<TreeNode*> v;

void pre_order(TreeNode *root)
{
    if (root == NULL) {
        return;
    }
    v.push_back(root);
    pre_order(root->left);
    pre_order(root->right);
}

void flatten1(TreeNode *root) {
    pre_order(root);
    for (int i = 1; i < v.size(); i++) {
        root->right = v.at(i);
        root = root->right;
    }
}


/**
 * 方法2:不再采取容器记录先根遍历序列，直接在先根遍历的过程中完成调整
 * 时间复杂度和空间复杂度仍为O(n),但是均好于方法1
 */

void flatten2(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    flatten2(root->left);
    flatten2(root->right);
    if (root->left != NULL) {
        TreeNode *right = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* current = root->right;
        while (current->right != NULL) {
            current = current->right;
        }
        current->right = right;
    }
}