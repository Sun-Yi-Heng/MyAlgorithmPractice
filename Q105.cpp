//
// Created by ��һ�� on 2020/3/6.
// Q105����ǰ��������������й��������
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
     * �ݹ�ⷨ
     * ����ǰ������ĵ�һ���ڵ��Ǹ��ڵ���һ���Զ����������һ�����֣��Ӷ��õ���ǰ�ڵ����������
     * ��������ǰ�����������������У�Ȼ��ݹ鼴�ɡ�
     * ���ڸ��ƻ����˽ϸߵ�ʱ�临�ӶȺͿռ临�Ӷȣ�O(n) = T(n) + T(n-1) + T(n-2)...���ʱ�临�ӶȺͿռ临�Ӷȶ�ΪO(n^2)
     */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // ����ǰ������ĵ�һ��Ԫ�ؾ��Ǹ��ڵ㣬Ȼ����ݸ��ڵ㻮�������������ҵ�����������ǰ�����������������У�Ȼ��ݹ�
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
    * ����ͨ��ջʵ�ֵĵ����ⷨ,ͬʱ����������ݹ鷨�У�ͨ�����ƻ�����������ı������У�
     * ����ͨ��������ԭ�������е���ŷ�Χ��Ϊ���棬�Ľ���ʱ�临�ӶȺͿռ临�Ӷȴ�����
    */
    // IndexBoundary������һ�������⣬���ڵݹ�
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
        // parent_stack������Ӧboundary_stack���ڵ��Ӧ�ĸ��׽ڵ�,����������������������son���Ը���
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
