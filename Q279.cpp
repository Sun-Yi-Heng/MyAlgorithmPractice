//
// Created by 孙一恒 on 2020/3/31.
// Q279、完全平方数
//

#include "util.h"

class Solution {
    /**
     * 更好的求解方法! numSquares(n)=min(numSquares(n-k) + 1),k是完全平方数
     */
public:
    /**
     * 递归求解, 同样也可以使用迭代求解,即从较小部分像较大部分求解
     */
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }
        int s = sqrt(n);
        // 是完全平方数,返回1即可
        if (s * s == n) {
            return 1;
        } else {
            int minNum = INT_MAX;
            for (int i = 1; i <= n / 2; i++) {
                minNum = min(minNum, (numSquares(i) + numSquares(n - i)));
            }
            return minNum;
        }
    }

    /**
     * 方法2:刚才的方法存在大量的子问题重复计算,我们利用动态规划的思想,直接从较小数向目标值进行计算
     * 时间复杂度O(n * n),空间复杂度O(n)
     */
    int numSquares1(int n) {
        int dp[n];
        for (int i = 1; i <= n; i++) {
            // 首先判断当前数是否为完全平方数
            int s = sqrt(i);
            if (s * s == i) {
                dp[i - 1] = 1;
                continue;
            }
            int minNum = INT_MAX;
            for (int j = 1; j <= i / 2; j++) {
                minNum = min(minNum, (dp[j - 1] + dp[i - j - 1]));
            }
            dp[i - 1] = minNum;
        }
        return dp[n - 1];
    }

    /**
     * 方法2:刚才的方法存在大量的子问题重复计算,我们利用动态规划的思想,直接从较小数向目标值进行计算
     * 修改后的动态规划解法,时间复杂度约为O(n * 根号n),空间复杂度O(n)
     */
    int numSquares2(int n) {
        vector<int> square_vector;
        for (int i = 1; i * i <= n; i++) {
            square_vector.push_back(i * i);
        }
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int minNum = INT_MAX;
            for (int j = 0; j < square_vector.size() && square_vector[j] <= i; j++) {
                minNum = min(minNum, 1 + dp[i - square_vector[j]]);
            }
            dp[i] = minNum;
        }
        return dp[n];
    }

    /**
     * BFS求解
     */
    int numSquares3(int n) {
        set<int> square_vector;
        for (int i = 1; i * i <= n; i++) {
            square_vector.insert(i * i);
        }
        queue<int> currentQueue;
        currentQueue.push(n);
        int num = 1;
        while (true) {
            int top = currentQueue.front();
            currentQueue.pop();
            if (square_vector.find(top) != square_vector.end()) {
                return num;
            }
        }
    }
};

