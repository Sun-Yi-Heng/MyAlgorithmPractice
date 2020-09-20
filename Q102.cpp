//
// Created by 孙一恒 on 2020/3/4.
// Q102、二叉树的层次遍历
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
     * 进行层层遍历,从而求得结果,该方法的时间复杂度为O(n)，空间复杂度为O(n)
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
     * 递归解法,采取深度优先搜索对应的递归解法
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