//
// Created by ��һ�� on 2020/2/2.
// 70����¥��
//

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * �����������򵥵ķ�������ʹ�õݹ�---����!ʱ�临�Ӷȡ��ռ临�Ӷȹ���Ϊ2^n��(�����γɵĵݹ������Թ���)
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
     * ��һ������:���ѿ���������һ����̬�滮����,����������n��쳲�������,����ֻ��Ҫ�ӵ�λ��ʼ���㼴��,ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n);
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

     // �Ż�����2,���ǲ���Ҫ�������ռ伴�ɼ���õ����
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
