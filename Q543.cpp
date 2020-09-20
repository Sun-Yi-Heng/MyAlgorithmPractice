//
// Created by 孙一恒 on 2020/5/23.
// Q543、二叉树的直径
//

#include "util.h"

class Solution {
public:
    int result = 0;
    /**
     * 由于每一个节点都可能作为根节点,其到左右子树两条路径合起来的长度是我们要求的最长长度
     * 因此,我们在求深度的过程中,用result比较和记录找到所求的最长长度。
     * 时间复杂度O(n),因为每个节点仅访问了一次。
     */
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        getMaxDepth(root);
        return result;
    }

    /**
     * 该函数的定义是获得从current出发到叶子节点的最大深度
     */
    int getMaxDepth(TreeNode* current) {
        if (current == NULL) {
            return 0;
        }
        int left = getMaxDepth(current->left);
        int right = getMaxDepth(current->right);
        result = max(result, left + right);
        return max(left, right) + 1;
    }
};

