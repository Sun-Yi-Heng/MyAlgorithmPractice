//
// Created by 孙一恒 on 2020/3/3.
// Q98、验证二叉搜索树
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
     * 递归解法,因为对于二叉搜索树,其左子树上的全部节点应当全部小于根节点,而不只是根节点的左子节点,
     * 右子树同理,因此设置了上下界来帮助计算
     * 思考,有没有办法不使用INT_MAX和INT_MIN?
     * @return
     */
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {
            return recursive(root, LONG_MAX, LONG_MIN);
        }
    }

    bool recursive(TreeNode* root, long up_bound, long low_bound) {
        if (root->val >= up_bound || root->val <= low_bound) {
            return false;
        }
        bool left = true, right = true;
        if (root->left != NULL) {
            left = recursive(root->left, root->val, low_bound);
        }
        if (root->right != NULL) {
            right = recursive(root->right, up_bound, root->val);
        }
        return left && right;
    }

    /**
     * 采用迭代解法,由于我们知道对于二叉搜索树,其中序遍历得到的结果是升序序列,所以问题转化为如何迭代完成对二叉树的中序遍历
     * 这种迭代方法是我最开始想到的方法,但是该方法破坏了原有的树的结构
     */
    bool isValidBST1(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        long current = LONG_MIN, previous = LONG_MIN;
        stack<TreeNode*> s;
        while (s.size() != 0) {
            TreeNode* top = s.top();
            if (top->left != NULL) {
                s.push(top->left);
                top->left = NULL;
            } else {
                s.pop();
                current = top->val;
                if (current <= previous) {
                    return false;
                }
                previous = current;
                if (top->right != NULL) {
                    s.push(top->right);
                }
            }
        }
        return true;
    }

    /**
     * 迭代中序遍历二叉树法2，不改变树的结构
     */
    bool isValidBST2(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        long current = LONG_MIN, previous = LONG_MIN;
        stack<TreeNode*> s;
        TreeNode* currNode = root;
        while (currNode != NULL || s.size() != 0) {
            while (currNode != NULL) {
                s.push(currNode);
                currNode = currNode->left;
            }
            currNode = s.top();
            s.pop();
            current = currNode->val;
            if (previous >= current) {
                return false;
            }
            previous = current;
            currNode = currNode->right;
        }
        return true;
    }

    /**
     * 转换思路,不是利用中序遍历,而是利用迭代的方法求解
     * @param root
     * @return
     */
    bool isValidBST3(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        stack<TreeNode*> s;
        stack<long> up_stack;
        stack<long> down_stack;
        helper(root, LONG_MIN, LONG_MAX, s, down_stack, up_stack);
        while (s.size() != 0) {
            TreeNode* current = s.top();
            long up = up_stack.top();
            long down = down_stack.top();
            s.pop();
            up_stack.pop();
            down_stack.pop();
            if (current->val <= down || current->val >= up) {
                return false;
            } else {
                if (current->left != NULL) {
                    helper(current->left, down, current->val, s, down_stack, up_stack);
                }
                if (current->right != NULL) {
                    helper(root, current->val, up, s, down_stack, up_stack);
                }
            }
        }
        return true;
    }

    void helper(TreeNode* t, long d, long u, stack<TreeNode*>& s, stack<long>& down, stack<long>& upper) {
        s.push(t);
        down.push(d);
        upper.push(u);
    }
};