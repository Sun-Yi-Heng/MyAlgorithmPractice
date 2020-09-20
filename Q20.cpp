//
// Created by ��һ�� on 2020/9/19.
// Q20����Ч������
//

#include "util.h"

class Solution {
public:
    /**
     * ʹ��ջ��Э���ж�
     */
    bool isValid(string s) {
        // �����ж��ַ����Ƿ�Ϊ��
        if (s.size() == 0) {
            return true;
        }
        stack<char> judge_stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                judge_stack.push(s[i]);
            } else {
                if (judge_stack.size() == 0 || (judge_stack.top() == '(' && s[i] != ')') || (judge_stack.top() == '{' && s[i] != '}') || (judge_stack.top() == '[' && s[i] != ']')) {
                    return false;
                } else {
                    judge_stack.pop();
                }
            }
        }
        if (judge_stack.size() == 0) {
            return true;
        } else {
            return false;
        }
    }
};

