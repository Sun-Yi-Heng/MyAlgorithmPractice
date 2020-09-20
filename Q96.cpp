//
// Created by 孙一恒 on 2020/3/2.
// Q96、不同的二叉搜索树
//

class Solution {
public:
    /**
     * 用动态规划解决问题,如果有n个不同数字构成的序列,我们分别以第i个数字作为树根,则根据二叉搜索树的性质,
     * 前i-1个数字组成左子树,而后n-i个数字构成右子树,从而产生了重叠子问题
     */
    int numTrees(int n) {
        if (n <= 1) {
            return 1;
        }
        int nums[n + 1];
        // 只有一个节点时只有一种不同的二叉搜索树。
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

