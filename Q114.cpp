//
// Created by ��һ�� on 2020/1/30.
// ������ԭ��չ��Ϊ����
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
 * ����1:�۲������ʾ�����Կ���,���������ǰ����ȸ�������˳�����еģ����������Ƚ���һ���ȸ�������Ȼ��һ�����Ӽ��ɡ�
 * ʱ�临�Ӷ�:O(n),�ռ临�Ӷ�O(n)
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
 * ����2:���ٲ�ȡ������¼�ȸ��������У�ֱ�����ȸ������Ĺ�������ɵ���
 * ʱ�临�ӶȺͿռ临�Ӷ���ΪO(n),���Ǿ����ڷ���1
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