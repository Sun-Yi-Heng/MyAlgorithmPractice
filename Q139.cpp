//
// Created by ��һ�� on 2020/3/12.
// Q139�����ʲ��
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    map<char, vector<string>> m;
    /**
     * ��ȡ�ݹ�ͻ��ݷ�����鵱ǰ�ַ��������п���ǰ׺��Ȼ���ʣ�ಿ�ֽ��еݹ飬��������ַ������ҵ��ͷ���true��
     * ���ַ���������뵥��Ϊ"aaa...aab",�����ʱ�Ϊ["a","aa","aaa"....]�����������µ�ʱ�临�Ӷȱƽ�ΪO(n^n)
     */
    bool wordBreak(string s, vector<string>& wordDict) {
        // ��������ĸ�Ͷ�Ӧ�����б���ֵ�
        for (int i = 'a'; i <= 'z'; i++) {
            vector<string> empty_vector;
            m[i] = empty_vector;
        }
        for (string word : wordDict) {
            m[word.at(0)].push_back(word);
        }
        return backtrace(0, s);
    }

    bool backtrace(int start_position, string& s) {
        if (start_position == s.size()) {
            return true;
        }
        for (string possible : m[s.at(start_position)]) {
            // ���s��ʣ�೤�Ȳ�����ֱ�ӱȽ���һ�����ܵ��ַ���
            if (s.size() - start_position < possible.size()) {
                continue;
            } else {
                // �����ǰ�ַ������,��ݹ��ж���һ����
                if (possible.compare(s.substr(start_position, possible.size())) == 0) {
                    if (backtrace(start_position + possible.size(), s)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    /**
     * ͨ����̬�滮������,��������Ҫ֪������ǰn���ַ��Ƿ�����Ҫ������ݷ������ݹ飬
     * ��������������ñ����ƥ�䣬������������ص������⣬��Ϊ����ǰx���ַ��Ƿ�����Ҫ�󣬻��ݷ����᳢ܻ�Ը��ֿ��ܣ������ǲ�����������ƥ��ģ�ֻҪ��¼�ܷ�ƥ�伴�ɡ�
     * dp[n] = (dp[n-1] && set.contains(str[n-1:n]) || ....
     */
    bool wordBreak1(string s, vector<string>& wordDict) {
        set<string> str_set;
        for (string word : wordDict) {
            str_set.insert(word);
        }
        bool dp[s.size() + 1];
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            dp[i] = false;
            for (int j = 0; j < i; j++) {
                if (dp[j] && str_set.find(s.substr(j, i - j)) != str_set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

