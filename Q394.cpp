//
// Created by ��һ�� on 2020/5/5.
// Q394���ַ�������
//
#include "util.h"

class Solution {
public:
    /**
     *  �۲���Ŀ�е�����,���Կ����ַ����������Ƕ�ײ��ֵĽ��룬������ǲ��õݹ�ķ�����⣬�˴����Ǽȶ�Ƕ�ײ��ֵݹ�,Ҳ�Ժ���Ľ��еݹ�
     */
    string decodeString(string s) {
        // ������ַ����е�ǰ׺�п����ǲ��ظ����ַ���,�Ȼ�ȡ�ⲿ��
        string normalStr = "";
        int current_position = 0;
        for (current_position = 0; current_position < s.size() && (s[current_position] < '0' || s[current_position] > '9'); current_position++) {
            normalStr += s[current_position];
        }
        if (current_position == s.size()) {
            return normalStr;
        }
        // �Ȼ�ȡҪ�ظ��Ĵ���
        vector<char> numVector;
        for (; s[current_position] != '['; current_position++) {
            numVector.push_back(s[current_position]);
        }
        current_position++;
        int repeatTimes = 0;
        int i;
        for (i = 0; i < numVector.size(); i++) {
            repeatTimes += (numVector[i] - '0') * pow(10, (numVector.size() - i - 1));
        }
        // ����Ҫ����ظ����ַ���,���ڿ��ܴ���Ƕ��,��������Ҫ��ȡ�ӵ�һ��[����֮ƥ���]֮����ַ���,�ٶ���ݹ�Ľ��롣
        // ������ƥ�������е��ַ���,����ͨ��ջ����ɣ�Ҳ����ʹ��һ�������������
        string repeatStr = "";
        int bracket_counter = 1;
        while (bracket_counter != 0) {
            if (s[current_position] == ']') {
                bracket_counter--;
            } else if (s[current_position] == '[') {
                bracket_counter++;
            }
            repeatStr += s[current_position];
            current_position++;
        }
        return normalStr + getRepeatStr(decodeString(repeatStr.substr(0, repeatStr.size() - 1)), repeatTimes) + decodeString(s.substr(current_position));
    }

    string getRepeatStr(string str, int times) {
        string result = "";
        for (int i = 0; i < times; i++) {
            result += str;
        }
        return result;
    }
};