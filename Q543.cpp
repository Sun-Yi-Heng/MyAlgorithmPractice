//
// Created by ��һ�� on 2020/5/23.
// Q543����������ֱ��
//

#include "util.h"

class Solution {
public:
    int result = 0;
    /**
     * ����ÿһ���ڵ㶼������Ϊ���ڵ�,�䵽������������·���������ĳ���������Ҫ��������
     * ���,����������ȵĹ�����,��result�ȽϺͼ�¼�ҵ����������ȡ�
     * ʱ�临�Ӷ�O(n),��Ϊÿ���ڵ��������һ�Ρ�
     */
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        getMaxDepth(root);
        return result;
    }

    /**
     * �ú����Ķ����ǻ�ô�current������Ҷ�ӽڵ��������
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

