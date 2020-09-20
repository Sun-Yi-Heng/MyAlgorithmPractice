//
// Created by 孙一恒 on 2020/2/28.
//Q101、对称二叉树
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
     * 思路1:判断一颗二叉树是否为对称二叉树,我们只需要判断每一层是否满足要求,直到最后为止。
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
     * 解法2:通过递归求解,什么时候一个棵树是对称二叉树?当其左子树和右子树镜像对称时
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
     * 解法3:通过队列迭代求解求解
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
