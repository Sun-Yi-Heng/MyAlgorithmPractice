//
// Created by ��һ�� on 2020/3/4.
// Q102���������Ĳ�α���
//

#include <iostream>
#include <vector>
#include <queue>
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
     * ���в�����,�Ӷ���ý��,�÷�����ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(n)
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        vector<TreeNode*> current;
        current.push_back(root);
        while (current.size() != 0) {
            vector<int> layer_result;
            vector<TreeNode*> next_lawyer;
            for (TreeNode* node: current) {
                layer_result.push_back(node->val);
                if (node->left != NULL) {
                    next_lawyer.push_back(node->left);
                }
                if (node->right != NULL) {
                    next_lawyer.push_back(node->right);
                }
            }
            result.push_back(layer_result);
            current = next_lawyer;
        }
        return result;
    }

    /**
     * �ݹ�ⷨ,��ȡ�������������Ӧ�ĵݹ�ⷨ
     */
    vector<vector<int>> levelOrder1(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        recursive(0, root, result);
        return result;
    }

     void recursive(int lawyer_num, TreeNode* current, vector<vector<int>>& result) {
         if (result.size() <= lawyer_num) {
             vector<int> v = {current->val};
             result.push_back(v);
         } else {
             result[lawyer_num].push_back(current->val);
         }
         if (current->left != NULL) {
             recursive(lawyer_num + 1, current->left, result);
         }
        if (current->right != NULL) {
            recursive(lawyer_num + 1, current->right, result);
        }
     }
};