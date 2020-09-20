//
// Created by 孙一恒 on 2020/3/6.
// Q105、从前序与中序遍历序列构造二叉树
//

#include <iostream>
#include <vector>
#include <queue>
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
     * 递归解法
     * 利用前序遍历的第一个节点是根节点这一特性对中序遍历做一个划分，从而得到当前节点的左子树和
     * 右子树的前序遍历、中序遍历序列，然后递归即可。
     * 由于复制划分了较高的时间复杂度和空间复杂度，O(n) = T(n) + T(n-1) + T(n-2)...因此时间复杂度和空间复杂度都为O(n^2)
     */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 树的前序遍历的第一个元素就是根节点，然后根据根节点划分左右子树，找到左右子树的前序遍历和中序遍历序列，然后递归
        if (preorder.size() == 0) {
            return NULL;
        }
        int root_value = preorder[0];
        int partition;
        for (partition = 0; partition < inorder.size(); partition++) {
            if (inorder[partition] == root_value) {
                break;
            }
        }
        vector<int> left_preorder;
        vector<int> right_preorder;
        vector<int> left_inorder;
        vector<int> right_inorder;
        for (int i = 0; i < partition; i++) {
            left_preorder.push_back(preorder[i + 1]);
            left_inorder.push_back(inorder[i]);
        }
        for (int i = 0; i < preorder.size() - partition - 1; i++) {
            right_preorder.push_back(preorder[i + partition + 1]);
            right_inorder.push_back(inorder[i + partition + 1]);
        }
        TreeNode* current = new TreeNode(root_value);
        current->left = buildTree(left_preorder, left_inorder);
        current->right = buildTree(right_preorder, right_inorder);
        return current;
    }

    /**
    * 尝试通过栈实现的迭代解法,同时不再像上面递归法中，通过复制获得左右子树的遍历序列，
     * 而是通过计算在原遍历序列的序号范围作为代替，改进后时间复杂度和空间复杂度大大减少
    */
    // IndexBoundary定义了一个子问题，用于递归
    struct IndexBoundary{
        int preorder_start;
        int preorder_end;
        int inorder_start;
        int inorder_end;
        char son;
        IndexBoundary(int preorder_start, int preorder_end, int inorder_start, int inorder_end, char son)
        : preorder_start(preorder_start), preorder_end(preorder_end), inorder_start(inorder_start), inorder_end(inorder_end), son(son){}
    };

    TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        TreeNode* init_node = new TreeNode(-1);
        IndexBoundary* init = new IndexBoundary(0, preorder.size() - 1, 0, inorder.size() - 1, 'l');
        stack<IndexBoundary*> boundary_stack;
        // parent_stack保存相应boundary_stack根节点对应的父亲节点,而是左子树还是右子树由son属性给出
        stack<TreeNode*> parent_stack;
        parent_stack.push(init_node);
        boundary_stack.push(init);
        while (parent_stack.size() != 0) {
            IndexBoundary* current_boundary = boundary_stack.top();
            TreeNode* parent_node = parent_stack.top();
            boundary_stack.pop();
            parent_stack.pop();
            if (current_boundary->inorder_end < current_boundary->inorder_start) {
                continue;
            }
            int current_val = preorder[current_boundary->preorder_start];
            int partition;
            for (partition = current_boundary->inorder_start;
                 partition <= current_boundary->inorder_end; partition++) {
                if (current_val == inorder[partition]) {
                    break;
                }
            }
            TreeNode* current_node = new TreeNode(current_val);
            if (current_boundary->son == 'l') {
                parent_node->left = current_node;
            } else if (current_boundary->son == 'r') {
                parent_node->right = current_node;
            }
            IndexBoundary* left_boundary = new IndexBoundary(current_boundary->preorder_start + 1, current_boundary->preorder_start + partition - current_boundary->inorder_start,
                    current_boundary->inorder_start, partition - 1, 'l');
            IndexBoundary* right_boundary = new IndexBoundary(current_boundary->preorder_start + partition - current_boundary->inorder_start + 1, current_boundary->preorder_end,
                    partition + 1, current_boundary->inorder_end, 'r');
            parent_stack.push(current_node);
            parent_stack.push(current_node);
            boundary_stack.push(left_boundary);
            boundary_stack.push(right_boundary);
        }
        return init_node->left;
    }
};
