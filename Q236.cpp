//
// Created by 孙一恒 on 2020/3/25.
// Q236、二叉树的最近公共祖先
//

#include "util.h"

class Solution {
public:
    TreeNode* ancestor = NULL;
    bool set = false;
    /**
     * 方法1:
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findTwoNode(root, p, q);
        return ancestor;
    }

    /**
     * 递归法求解,相当于在二叉树中递归的查找两个节点,并且将第一次可以查找到p、q的根节点设置为我们所求的结果
     * 这是由于递归是栈结构,返回时第一个满足要求的节点就是最近公共祖先
     * 时间复杂度O(n)、空间复杂度O(lgn)
     */
    int findTwoNode(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return 0;
        }
        int left_result = findTwoNode(root->left, p, q);
        int right_result = findTwoNode(root->right, p, q);
        int result = (root == p) + (root == q) + left_result + right_result;
        if (result == 2 && ancestor != NULL) {
            ancestor = root;
        }
        return result;
    }

    /**
     * 迭代算法,利用栈DFS二叉树,并保存节点和对应父节点的映射关系,直到找到两个要查找节点为止。
     * 之后用集合保存其中一个查找节点的所有父亲节点,然后开始对另一个节点的父亲节点逐层向上遍历,
     * 当其存在与另一个节点的父亲节点集合时,该节点即为所求
     * 时间复杂度O(N),空间复杂度O(N)
     */
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return root;
        }
        unordered_map<TreeNode*, TreeNode*> son_parent_map;
        son_parent_map[root] = NULL;
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (son_parent_map.find(p) == son_parent_map.end() || son_parent_map.find(q) == son_parent_map.end()) {
            TreeNode *current = node_stack.top();
            node_stack.pop();
            if (current->right != NULL) {
                son_parent_map[current->right] = current;
                node_stack.push(current->right);
            }
            if (current->left != NULL) {
                son_parent_map[current->left] = current;
                node_stack.push(current->left);
            }
        }
        unordered_set<TreeNode*> p_parent;
        TreeNode* current = p;
        p_parent.insert(current);
        while (son_parent_map.find(current)->second != NULL) {
            current = son_parent_map.find(current)->second;
            p_parent.insert(current);
        }
        current = q;
        while (p_parent.find(current) == p_parent.end()) {
            current = son_parent_map.find(current)->second;
        }
        return current;
    }
};

