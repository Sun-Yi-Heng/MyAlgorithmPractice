//
// Created by 孙一恒 on 2020/4/17.
// Q301、删除无效的括号
//
#include "util.h"

class Solution {
public:
    /**
     * 通过BFS的方法,逐层移除s中的一个括号,如果在某一层中第一次发现了合法的括号,就返回这一层中所有合法括号即可。
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
     * 判定给定的字符串括号是否匹配,使用栈进行判断
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
