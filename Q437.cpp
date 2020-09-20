//
// Created by ��һ�� on 2020/5/20.
// Q437��·���ܺ�
//

#include "util.h"

class Solution {
public:
    /**
     * ���ڲ���Ҫ�Ӹ��ڵ㿪ʼ,Ҳ����Ҫ��Ҷ�ӽڵ����,��������ֻ��Ҫ��root�е�ÿһ���ڵ㿪ʼ,��ȥ����ӵ�ǰ�ڵ����
     * �����ӽڵ�,�ܷ��ҵ�һ�����Ϊsum��·��
     */
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        int result = 0;
        stack<pair<TreeNode*, int>> problem_stack;
        pair<TreeNode *, int> start_problem(root, root->val);
        problem_stack.push(start_problem);
        while (problem_stack.size() != 0) {
            auto current_problem = problem_stack.top();
            problem_stack.pop();
            if (current_problem.second == sum) {
                result++;
            }
            if (current_problem.first->left != NULL) {
                pair<TreeNode *, int> son_problem(current_problem.first->left, current_problem.second + current_problem.first->left->val);
                pair<TreeNode *, int> left_new_problem(current_problem.first->left, current_problem.first->left->val);
                problem_stack.push(son_problem);
                problem_stack.push(left_new_problem);
            }
            if (current_problem.first->right != NULL) {
                pair<TreeNode *, int> son_problem(current_problem.first->right, current_problem.second + current_problem.first->right->val);
                pair<TreeNode *, int> right_new_problem(current_problem.first->right, current_problem.first->right->val);
                problem_stack.push(son_problem);
                problem_stack.push(right_new_problem);
            }
        }
        return result;
    }

    /**
     * ����2:ͨ���ݹ��������
     */
    int pathSum1(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        int current_result = countPath(root, sum);
        int left_result = pathSum1(root->left, sum);
        int right_result = pathSum1(root->right, sum);
        return current_result + left_result + right_result;
    }

    int countPath(TreeNode* root,int sum){
        if(root == NULL){
            return 0;
        }
        sum = sum - root->val;
        int result = sum == 0 ? 1:0;
        return result + countPath(root->left,sum) + countPath(root->right,sum);
    }
};

