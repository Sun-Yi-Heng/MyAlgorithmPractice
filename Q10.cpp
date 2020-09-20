//
// Created by ��һ�� on 2020/6/9.
// Q10��������ʽƥ��
//
#include "util.h"

class Solution {
public:
    /**
     * ����1:����������ʽ���бȽ�,�������*�Ļ�,��ö�����еĿ��ܲ������ݹ鴦��
     * �㷨��ʱ�临�Ӷ���Ҫȡ����*,��LeetCode�б��ֽϲ�
     */
    bool isMatch(string s, string p) {
        // ��ʼ���бȽ�
        int current = 0;
        // ������Ҫ��Ҫ�������"*"
        while (p[current + 1] != '*' && current < p.length() && current < s.length()) {
            if (p[current] == s[current] || p[current] == '.') {
                current++;
            } else {
                return false;
            }
        }
        // �����ǰ����Ϊcurrent�������ַ�����Χ������ѭ����
        if (current >= p.length() || current >= s.length()) {
            // ���ڶ���pattern����current��Ȼû�е���ͷ,������Ȼ���ԱȽ�������(������*),������������������
            int p_current = current;
            if (current < p.length()) {
                while (p_current + 1 < p.length() && p[p_current + 1] == '*') {
                    p_current += 2;
                }
            }
            return p_current == p.length() && current == s.length();
        }
            // current����Ϊp[current + 1] = '*' ��������,�һ�û�бȽϵ�ĩβ
        else {
            // ʹ�õ�ǰ��*ƥ�����п���������s(��0��ʼ)
            // ƥ��0��
            if (isMatch(s.substr(current), p.substr(current + 2))) {
                return true;
            }
            // ƥ���������ܵĴ���
            for (int i = current; i < s.length() && (s[i] == p[current] || p[current] == '.'); i++) {
                if (isMatch(s.substr(i + 1), p.substr(current + 2))) {
                    return true;
                }
            }
            // �����еĻ�,����false
            return false;
        }
    }

    /**
     * ��̬�滮��:״̬dp[i][j]����s[0:i]��p[0:j]�Ƿ�ƥ��,��������״̬���µ�״̬
     * ʱ�临�ӶȺͿռ临�ӶȾ�ΪO(M*N),M��N�ֱ����ַ���s��p�ĳ���
     */
    bool isMatch1(string s, string p) {
        s = " " + s;
        p = " " + p;
        bool dp[s.length() + 1][p.length() + 1];
        memset(dp, false, (s.length() + 1) * (p.length() + 1));
        dp[0][0] = true;
        for (int i = 1; i < s.length(); i++) {
            for (int j = 1; j < p.length(); j++) {
                // ���1
                if (s[i] == p[j] || p[j] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j] == '*') {
                    if (p[j - 1] == s[i] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                    } else {
                        dp[i][j] = (j - 2 >= 0) ? dp[i][j - 2] : false;
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};
