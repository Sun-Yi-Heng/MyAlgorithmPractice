//
// Created by ��һ�� on 2020/5/29.
// Q647�������Ӵ�
//

#include "util.h"

class Solution {
public:
    /**
     * �ж��ַ���s�Ƿ�Ϊ�����Ӵ�
     */
    bool judge(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }

    /**
     * ����1:����ö�����п��ܵ��Ӵ�,�������ж�,�ʱ�临�Ӷ�O(n^3)
     */
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (judge(s.substr(i, j - i + 1))) {
                    count++;
                }
            }
        }
        return count;
    }

    /**
     * ����2:Ҳ��������չ��
     * ���ڻ��Ĵ������Ŀ�����������ĸ֮��,Ҳ���ܾ���ĳһ����ĸ,�������ǳ�����ÿһ�����ܵ�Ϊֹ��Ϊ����
     * �ҳ�����Ϊ���ĵ����л��Ĵ�����
     * �ʱ�临�Ӷ�O(N^2)
     */
    int countSubstrings1(string s) {
        int count = 0, left, right;
        int possible_middle = 2 * s.size() - 1;
        for (int i = 0; i < possible_middle; i++) {
            if (i % 2 == 0) {
                left = i / 2;
                right = i / 2;
            } else {
                left = i / 2;
                right = i / 2 + 1;
            }
            while (left >= 0 && right < s.size()) {
                if (s[left] == s[right]) {
                    count++;
                    left--;
                    right++;
                } else {
                    break;
                }
            }
        }
        return count;
    }
};
