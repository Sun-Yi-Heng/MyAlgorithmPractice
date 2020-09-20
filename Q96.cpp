//
// Created by ��һ�� on 2020/3/2.
// Q96����ͬ�Ķ���������
//

class Solution {
public:
    /**
     * �ö�̬�滮�������,�����n����ͬ���ֹ��ɵ�����,���Ƿֱ��Ե�i��������Ϊ����,����ݶ���������������,
     * ǰi-1���������������,����n-i�����ֹ���������,�Ӷ��������ص�������
     */
    int numTrees(int n) {
        if (n <= 1) {
            return 1;
        }
        int nums[n + 1];
        // ֻ��һ���ڵ�ʱֻ��һ�ֲ�ͬ�Ķ�����������
        nums[0] = 1;
        nums[1] = 1;
        for (int i = 2; i <= n; i++) {
            int current_num = 0;
            for (int j = 0; j < i; j++) {
                current_num += nums[j] * nums[i - j - 1];
            }
            nums[i] = current_num;
        }
        return nums[n];
    }
};

