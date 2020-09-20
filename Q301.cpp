//
// Created by ��һ�� on 2020/4/17.
// Q301��ɾ����Ч������
//
#include "util.h"

class Solution {
public:
    /**
     * ͨ��BFS�ķ���,����Ƴ�s�е�һ������,�����ĳһ���е�һ�η����˺Ϸ�������,�ͷ�����һ�������кϷ����ż��ɡ�
     */
    vector<string> removeInvalidParentheses(string s) {
        set<string> current_set;
        current_set.insert(s);
        vector<string> result;
        while (current_set.size() != 0 && result.size() == 0) {
            set<string> next_set;
            for (auto it = current_set.begin(); it != current_set.end(); it++) {
                string current_string = *it;
                if (judgeValidBracket(current_string)) {
                    result.push_back(current_string);
                }
                for (int i = 0; i < current_string.size(); i++) {
                    if (current_string.at(i) == '(' || current_string.at(i) == ')') {
                        next_set.insert(current_string.substr(0 , i) + current_string.substr(i + 1));
                    }
                }
            }
            current_set = next_set;
        }
        return result;
    }

    /**
     * �ж��������ַ��������Ƿ�ƥ��,ʹ��ջ�����ж�
     */
    bool judgeValidBracket(string s) {
        int counter = 0;
        for (int i = 0; i < s.size() && counter >= 0; i++) {
            if (s.at(i) == '(') {
                counter++;
            } else if (s.at(i) == ')') {
                counter--;
            }
        }
        return counter == 0;
    }
};
