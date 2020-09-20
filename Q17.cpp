//
// Created by ��һ�� on 2020/9/15.
// Q17���绰��������
//
#include "util.h"

class Solution {
public:
    // ���ȳ�ʼ�����ǵ�map
    unordered_map<char, vector<char>> phone_map = {
            pair<char, vector<char>>('2', {'a', 'b', 'c'}), pair<char, vector<char>>('3', {'d', 'e', 'f'}),
            pair<char, vector<char>>('4', {'g', 'h', 'i'}), pair<char, vector<char>>('5', {'j', 'k', 'l'}),
            pair<char, vector<char>>('6', {'m', 'n', 'o'}), pair<char, vector<char>>('7', {'p', 'q', 'r', 's'}),
            pair<char, vector<char>>('8', {'t', 'u', 'v'}), pair<char, vector<char>>('9', {'w', 'x', 'y', 'z'})};

    /**
     * ����1:���õ����ķ���
     */
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)  {
            return vector<string>();
        }
        vector<string> result = {""};
        for (int i = 0; i < digits.size(); i++) {
            vector<string> next_combination;
            for (string s : result) {
                for (char c : phone_map.find(digits[i])->second) {
                    next_combination.push_back(s + c);
                }
            }
            result = next_combination;
        }
        return result;
    }

    /**
     * ����2:���û��ݷ�
     */
    vector<string> result = {};
    vector<string> letterCombinations1(string digits) {
        if (digits.size() == 0)  {
            return result;
        }
        backtrace(digits, "");
        return result;
    }

    void backtrace(string remain_digits, string current) {
        if (remain_digits.size() == 0) {
            result.push_back(current);
            return;
        }
        for (char c : phone_map.find(remain_digits[0])->second) {
            backtrace(remain_digits.substr(1), current + c);
        }
    }
};
