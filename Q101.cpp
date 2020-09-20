//
// Created by ��һ�� on 2020/2/28.
//Q101���Գƶ�����
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    /**
     * ˼·1:�ж�һ�Ŷ������Ƿ�Ϊ�Գƶ�����,����ֻ��Ҫ�ж�ÿһ���Ƿ�����Ҫ��,ֱ�����Ϊֹ��
     * @param root
     * @return
     */
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> currentLawyer = {root};
        bool go_on = true;
        while (go_on) {
            go_on = false;
            vector<TreeNode*> nextLawyer;
            for (int i = 0; i < currentLawyer.size(); i++) {
                int mirror_index = currentLawyer.size() - i - 1;
                if (currentLawyer[i] && currentLawyer[mirror_index]) {
                    if (currentLawyer[i]->val != currentLawyer[mirror_index]->val) {
                        return false;
                    }
                } else {
                    if (currentLawyer[i] != currentLawyer[mirror_index]) {
                        return false;
                    }
                }

                if (currentLawyer[i] != NULL) {
                    go_on = true;
                    nextLawyer.push_back(currentLawyer[i]->left);
                    nextLawyer.push_back(currentLawyer[i]->right);
                } else {
                    nextLawyer.push_back(NULL);
                    nextLawyer.push_back(NULL);
                }
            }
            currentLawyer = nextLawyer;
        }
        return true;
    }

    /**
     * �ⷨ2:ͨ���ݹ����,ʲôʱ��һ�������ǶԳƶ�����?����������������������Գ�ʱ
     */
    bool isSymmetric1(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode *left, TreeNode *right) {
        if (left == NULL || right == NULL) {
            return left == right;
        }
        if (left->val == right->val) {
            return isMirror(left->left, right->right) && isMirror(left->right, right->left);
        } else {
            return false;
        }
    }

    /**
     * �ⷨ3:ͨ�����е���������
     */
    bool isSymmetric2(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == NULL) {
            return true;
        }
        q.push(root->left);
        q.push(root->right);
        while (q.size() != 0) {
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();
            if (t1 == NULL || t2 == NULL) {
                if (t1 == t2) {
                    continue;
                } else {
                    return false;
                }
            } else {
                if (t1->val == t2->val) {
                    q.push(t1->left);
                    q.push(t2->right);
                    q.push(t1->right);
                    q.push(t2->left);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
