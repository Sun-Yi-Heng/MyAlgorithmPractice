//
// Created by 孙一恒 on 2020/5/5.
// Q394、字符串解码
//
#include "util.h"

class Solution {
public:
    /**
     *  观察题目中的描述,可以看到字符串解码包括嵌套部分的解码，因此我们采用递归的方法求解，此处我们既对嵌套部分递归,也对后面的进行递归
     */
    string decodeString(string s) {
        // 传入的字符串中的前缀有可能是不重复的字符串,先获取这部分
        string normalStr = "";
        int current_position = 0;
        for (current_position = 0; current_position < s.size() && (s[current_position] < '0' || s[current_position] > '9'); current_position++) {
            normalStr += s[current_position];
        }
        if (current_position == s.size()) {
            return normalStr;
        }
        // 先获取要重复的次数
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
        // 接着要获得重复的字符串,由于可能存在嵌套,所以我们要获取从第一个[到与之匹配的]之间的字符串,再对齐递归的解码。
        // 这里获得匹配括号中的字符串,可以通过栈来完成，也可以使用一个计数器来完成
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