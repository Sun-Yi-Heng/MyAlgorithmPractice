//
// Created by 孙一恒 on 2020/3/12.
// Q139、单词拆分
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
     * 采取递归和回溯法，检查当前字符串的所有可能前缀，然后对剩余部分进行递归，如果整个字符串都找到就返回true。
     * 这种方法如果输入单词为"aaa...aab",而单词表为["a","aa","aaa"....]则这种最坏情况下的时间复杂度逼近为O(n^n)
     */
    bool wordBreak(string s, vector<string>& wordDict) {
        // 保存首字母和对应单词列表的字典
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
            // 如果s的剩余长度不够，直接比较下一个可能的字符串
            if (s.size() - start_position < possible.size()) {
                continue;
            } else {
                // 如果当前字符串相等,则递归判断下一部分
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
     * 通过动态规划求解该题,我们所需要知道的是前n个字符是否满足要求。像回溯法那样递归，
     * 如果不行再重新用别的项匹配，会产生大量的重叠子问题，因为对于前x个字符是否满足要求，回溯法可能会尝试各种可能，而我们不关心是怎样匹配的，只要记录能否匹配即可。
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

