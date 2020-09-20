//
// Created by ��һ�� on 2020/6/17.
// Q13����������ת����
//
#include "util.h"

class Solution {
public:
    /**
     * ��ͷ��ʼ�Ƚ�,���s�ĵ�ǰ�ַ��������ֵ������һ���ַ�,����ϵ�ǰ�ַ�,�����ж���һ���ַ�
     * ���s�ĵ�ǰ�ַ��������ֵС����һ���ַ�,���ȥ��ǰ�ַ���������һ���ַ�,�����ж����¸��ַ�
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
