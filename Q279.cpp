//
// Created by ��һ�� on 2020/3/31.
// Q279����ȫƽ����
//

#include "util.h"

class Solution {
    /**
     * ���õ���ⷽ��! numSquares(n)=min(numSquares(n-k) + 1),k����ȫƽ����
     */
public:
    /**
     * �ݹ����, ͬ��Ҳ����ʹ�õ������,���ӽ�С������ϴ󲿷����
     */
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }
        int s = sqrt(n);
        // ����ȫƽ����,����1����
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
     * ����2:�ղŵķ������ڴ������������ظ�����,�������ö�̬�滮��˼��,ֱ�Ӵӽ�С����Ŀ��ֵ���м���
     * ʱ�临�Ӷ�O(n * n),�ռ临�Ӷ�O(n)
     */
    int numSquares1(int n) {
        int dp[n];
        for (int i = 1; i <= n; i++) {
            // �����жϵ�ǰ���Ƿ�Ϊ��ȫƽ����
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
     * ����2:�ղŵķ������ڴ������������ظ�����,�������ö�̬�滮��˼��,ֱ�Ӵӽ�С����Ŀ��ֵ���м���
     * �޸ĺ�Ķ�̬�滮�ⷨ,ʱ�临�Ӷ�ԼΪO(n * ����n),�ռ临�Ӷ�O(n)
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
     * BFS���
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

