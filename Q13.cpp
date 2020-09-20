//
// Created by 孙一恒 on 2020/6/17.
// Q13、罗马数字转整数
//
#include "util.h"

class Solution {
public:
    /**
     * 从头开始比较,如果s的当前字符代表的数值大于下一个字符,则加上当前字符,继续判断下一个字符
     * 如果s的当前字符代表的数值小于下一个字符,则减去当前字符并加上下一个字符,继续判断下下个字符
     */
    int romanToInt(string s) {
        unordered_map<char, int> money_map = {pair<char, int>('I', 1), pair<char, int>('V', 5), pair<char, int>('X', 10),
                                              pair<char, int>('L', 50), pair<char, int>('C', 100), pair<char, int>('D', 500),
                                              pair<char, int>('M', 1000)};
        int result = 0;
        for (int i = 0; i < s.size(); ) {
            if (i + 1 >= s.size() || money_map.find(s[i])->second >= money_map.find(s[i + 1])->second) {
                result += money_map.find(s[i])->second;
                i++;
            } else {
                result = result - money_map.find(s[i])->second + money_map.find(s[i + 1])->second;
                i += 2;
            }
        }
        return result;
    }
};
