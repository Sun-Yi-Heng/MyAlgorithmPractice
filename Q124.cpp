//
// Created by ��һ�� on 2020/3/8.
// Q124���������е����·����
//
#include <iostream>
#include <vector>
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
     * ���η�+�������������
     * ��������в��,ԭ����Ľ���ڶ��������������������ͼ��㾭����ǰ���ڵ�����·���͵���max��
     * ��merge��ʱ�临�Ӷ�Ϊ
     */
    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return root->val;
        }
        return max(max(maxPathSum(root->left), maxPathSum(root->right)), merge(root));
    }

    // ��μ��㾭�����ڵ����ͨ����������һ��·���,���ݷ�
    int merge(TreeNode *root_node) {
        int left_length = 0;
        int right_length = 0;
        int max_path = root_node->val;
        if (root_node->left != NULL) {
            // ����stack�ֱ�洢�Ӹ��ڵ㵽�������ĵ�ǰ�ڵ�Ͷ�Ӧ��·������
            stack<int> path_length_stack;
            stack<TreeNode*> node_stack;
            node_stack.push(root_node->left);
            path_length_stack.push(root_node->left->val);
            left_length = DFS_maxLength(path_length_stack, node_stack);
        }
        if (root_node->right != NULL) {
            // ����stack�ֱ�洢�Ӹ��ڵ㵽�������ĵ�ǰ�ڵ�Ͷ�Ӧ��·������
            stack<int> path_length_stack;
            stack<TreeNode*> node_stack;
            node_stack.push(root_node->right);
            path_length_stack.push(root_node->right->val);
            right_length = DFS_maxLength(path_length_stack, node_stack);
        }
        if (left_length > 0) {
            max_path += left_length;
        }
        if (right_length > 0) {
            max_path += right_length;
        }
        return max_path;
    }

    int DFS_maxLength(stack<int> path_length_stack, stack<TreeNode*> node_stack) {
        int max_path = 0;
        while (node_stack.size() != 0) {
            TreeNode* current = node_stack.top();
            int current_length = path_length_stack.top();
            max_path = max(current_length, max_path);
            node_stack.pop();
            path_length_stack.pop();
            if (current->right != NULL) {
                node_stack.push(current->right);
                path_length_stack.push(current_length + current->right->val);
            }
            if (current->left != NULL) {
                node_stack.push(current->left);
                path_length_stack.push(current_length + current->left->val);
            }
        }
        return max_path;
    }
};

