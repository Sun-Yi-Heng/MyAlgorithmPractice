//
// Created by 孙一恒 on 2020/2/17.
// Q72、编辑距离
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * 动态规划
     */
    int minDistance(string word1, string word2) {
        int dp[word1.size() + 1][word2.size() + 1];
        dp[0][0] = 0;
        for (int i = 0; i < word1.size(); i++) {
            dp[i + 1][0] = i + 1;
        }
        for (int j = 0; j < word2.size(); j++) {
            dp[0][j + 1] = j + 1;
        }
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1.at(i - 1) == word2.at(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }

//    vector<map<int,int>> getAllLongestCommonSubsequence() {
//
//    }
};
