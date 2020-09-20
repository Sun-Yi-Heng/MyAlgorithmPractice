//
// Created by 孙一恒 on 2020/2/2.
// 70、爬楼梯
//

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 解决该问题最简单的方法就是使用递归---笨逼!时间复杂度、空间复杂度过高为2^n，(根据形成的递归树可以估算)
     * @param n
     * @return
     */
    int climbStairs1(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        return climbStairs1(n - 1) + climbStairs1(n - 2);
    }

    /**
     * 进一步考虑:不难看出，这是一个动态规划问题,类似与求解第n个斐波那契数,我们只需要从低位开始计算即可,时间复杂度O(n)，空间复杂度O(n);
     */
     int climbStairs2(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
         int answer[n];
         answer[0] = 1;
         answer[1] = 2;
        for (int i = 2; i < n; i++) {
            answer[i] = answer[i - 1] + answer[i - 2];
        }
        return answer[n - 1];
     }

     // 优化方法2,我们不需要申请额外空间即可计算得到结果
    int climbStairs3(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int current_left = 1;
        int current_right = 2;
        int next;
        for (int i = 2; i < n; i++) {
            next = current_left + current_right;
            current_left = current_right;
            current_right = next;
        }
        return next;
    }
};
