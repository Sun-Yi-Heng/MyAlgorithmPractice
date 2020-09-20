//
// Created by ��һ�� on 2020/3/21.
// Q3�����ظ��ַ�����ִ�
//
#include "util.h"

class Solution {
public:
    /**
     * ���ƽⷨ:���ַ�����ÿ���ַ���Ϊ���,�������ظ��ַ����ִ�,������ļ�Ϊ����
     * ʱ�临�Ӷ�O(n^2) �ռ临�Ӷ�O(n)
     */
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        for (int i = 0; i < s.size(); i++) {
            set<char> char_set;
            for (int j = i; j < s.size(); j++) {
                if (char_set.find(s[j]) != char_set.end()) {
                    maxLength = max(maxLength, (int)char_set.size());
                    break;
                } else {
                    char_set.insert(s[j]);
                }
                if (j == s.size() - 1) {
                    maxLength = max(maxLength, (int)char_set.size());
                }
            }
        }
        return maxLength;
    }

    /**
     * �������ڷ�:ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
     * @param s
     * @return
     */
    int lengthOfLongestSubstring2(string s) {
        int maxLength = 0;
        unordered_map<char, int> char_index_map;
        int start_index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (char_index_map.find(s[i]) != char_index_map.end()) {
                start_index = max(char_index_map.find(s[i])->second + 1, start_index);
            }
            char_index_map[s[i]] = i;
            maxLength = max(maxLength, i - start_index + 1);
        }
        return maxLength;
    }

//    /**
//     * ���η�:���ǵ�merge()����ȽϺ�д,��ʱ�临�Ӷ�ΪO(n)
//     * ���ͨ�����η����Խ�ʱ�临�Ӷ��Ż���O(nlgn),�ռ临�Ӷ�ΪO(n)
//     */
//    int lengthOfLongestSubstring1(string s) {
//        return divide_and_conquer(s, 0, s.size() - 1);
//    }
//
//    int divide_and_conquer(string &s, int start, int end) {
//        if (start == end) {
//            return 1;
//        }
//        int middle = (start + end) / 2;
//        int max_left = divide_and_conquer(s, start, middle);
//        int max_right = divide_and_conquer(s, middle + 1, end);
//
//    }
//
//    int merge(string &s, int middle) {
//
//    }
};

