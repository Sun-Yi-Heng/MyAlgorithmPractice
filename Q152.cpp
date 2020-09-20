//
// Created by 孙一恒 on 2020/3/17.
// Q152、乘积最大子序列
//
#include "util.h"

class Solution {
public:
    /**
     * 方法1:暴力求解,计算所有可能的情况,时间复杂度为O(n^3),空间复杂度为O(1)
     */
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int current = 1;
                for (int k = i; k <= j; k++) {
                    current *= nums[k];
                }
                result = max(result, current);
            }
        }
        return result;
    }

    /**
     * 方法2:
     * 优化我们的枚举法,我们将上面的计算转化为一种自底向上的计算,消除重复计算,类似于动态规划。
     * 时间复杂度降低到O(n^2),空间复杂度提高到O(n^2)
     */
    int maxProduct1(vector<int>& nums) {
        int product[nums.size()][nums.size()];
        int result = nums[0];
        for (int gap = 0; gap < nums.size(); gap++) {
            for (int i = 0; i + gap < nums.size(); i++) {
                if (i + 1 > i + gap) {
                    product[i][i + gap] = nums[i];
                } else {
                    product[i][i + gap] = product[i][i] * product[i + 1][i + gap];
                }
                result = max(result, product[i][i + gap]);
            }
        }
        return result;
    }

    /**
     * 方法3:
     * 方法2在LeetCode出现了stack overflow错误,所以我们想进一步优化空间复杂度到O(n)
     * 时间复杂度为O(n^2),空间复杂度降低到O(n)
    */
    int maxProduct2(vector<int>& nums) {
        int previous_product[nums.size()];
        int result = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            previous_product[i] = nums[i];
            result = max(result, previous_product[i]);
        }
        for (int gap = 1; gap < nums.size(); gap++) {
            for (int i = 0; i + gap < nums.size(); i++) {
                previous_product[i] = nums[i] * previous_product[i + 1];
                result = max(result, previous_product[i]);
            }
        }
        return result;
    }


    /**
     * 方法3:动态规划
     * 用imax记录以当前节点作为终止节点的最大连续子序和
     * 用imin记录以当前节点作为终止节点的最小连续子序和
     * 这样我们以每一个节点作为终止节点,进行一轮比较后即可求得问题的解
     * 时间复杂度O(n),空间复杂度O(1)
     */
    int maxProduct3(vector<int>& nums) {
        int imax = 1, imin = 1, result = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                int temp = imax;
                imax = imin;
                imin = temp;
            }
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            result = max(imax, result);
        }
        return result;
    }

};

