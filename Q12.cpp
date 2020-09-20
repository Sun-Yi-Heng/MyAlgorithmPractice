//
// Created by 孙一恒 on 2020/6/17.
// Q12、整数转罗马数字
//
#include "util.h"

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> money_map = {pair<int, string>(1, "I"), pair<int, string>(4, "IV"),
                                               pair<int, string>(5, "V"), pair<int, string>(9, "IX"),
                                               pair<int, string>(10, "X"), pair<int, string>(40, "XL"),
                                               pair<int, string>(50, "L"),
                                               pair<int, string>(90, "XC"), pair<int, string>(100, "C"),
                                               pair<int, string>(400, "CD"), pair<int, string>(500, "D"),
                                                       pair<int, string>(900, "CM"),
                                               pair<int, string>(1000, "M")};
        string result = "";
        for (int i = money_map.size() - 1; i >= 0 && num != 0; i--) {
            while (num / money_map[i].first != 0) {
                result += money_map[i].second;
                num -= money_map[i].first;
            }
        }
        return result;
    }
};