//
// Created by ��һ�� on 2020/6/6.
// Q5��������Ӵ�
//

#include "util.h"

class Solution {
public:
    /**
     * ����1:�����ж�,ʱ�临�Ӷ���O(N^2)��O(N ^ 3)֮��,������ʱ������
     */
    string longestPalindrome(string s) {
        int max_length = 0;
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            // ����ֻ��Ҫ�ȽϿ��ܵĸ����Ļ����Ӵ�
            for (int j = i + max_length; j < s.size(); j++) {
                if (judge(s.substr(i, j - i + 1))) {
                    max_length = j - i + 1;
                    result = s.substr(i, j - i + 1);
                }
            }
        }
        return result;
    }

    // �ж�s�Ƿ���һ����Ļ����Ӵ�
    bool judge(string s) {
        for (int start = 0, end = s.size() - 1; start < end; start++, end--) {
            if (s[start] != s[end]) {
                return false;
            }
        }
        return true;
    }

    /**
     * ����2:���ڳ���Ϊn��s��˵,������2 * n - 1������Ϊ���ĵ�(��ÿ���ַ���Ϊ����/���ַ����ַ��м��λ����Ϊ����)
     * �õ���Ļ����Ӵ�����������Ҫ���������Ӵ�,����������β���
     * ʱ�临�Ӷ�O(N ^ 2)(ʵ���ύʱ,Ч�����)
     */
    string longestPalindrome1(string s) {
        if (s.length() < 2) {
            return s;
        }
        int max_length = 1;
        int start_index = 0;
        // ö�����п��ܵ����ĵ�,Ȼ���ÿ�����ĵ������ɢ
        for (int i = 0; i <= 2 * s.length() - 1; i++) {
            int left = (i - 1) / 2;
            int right = i / 2 + 1;
            for (; left >= 0 && right < s.length(); left--, right++) {
                if (s[left] != s[right]) {
                    break;
                }
            }
            if (max_length < (right - left - 1)) {
                max_length = right - left - 1;
                start_index = left + 1;
            }
        }
        return s.substr(start_index, max_length);
    }

    /**
     * ����3:��̬�滮,dp[i][j]�����s[i]��s[j]���ַ����Ƿ�Ϊ�����Ӵ�
     * ��dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j]
     * ����,���Ĺ�����,����ֻ��Ҫ���������ǵĲ��ּ���,�Ұ��վ�������
     * ʱ�临�Ӷ�O(N ^ 2)���ռ临�Ӷ�O(N ^ 2)
     */
    string longestPalindrome2(string s) {
        // �����������
        if (s.size() <= 1) {
            return s;
        }
        int max_length = 1;
        int start_index = 0;
        bool dp[s.size()][s.size()];
        // ��ʼ��
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                dp[i][j] = i == j;
            }
        }
        // ��ʼ���
        for (int gap = 1; gap < s.size(); gap++) {
            for (int i = 0; i + gap < s.size(); i++) {
                int j = i + gap;
                dp[i][j] = ((i + 1 <= j - 1) ? dp[i + 1][j - 1] : true) && s[i] == s[j];
                if (dp[i][j] && j - i + 1 > max_length) {
                    max_length = j - i + 1;
                    start_index = i;
                    // û��Ҫ������ֱ�ӽ��н�ȡ,��Ϊ��ȡҲ��������
//                    result = s.substr(i, j - i + 1);
                }
            }
        }
        return s.substr(start_index, max_length);
    }
};

