//
// Created by 孙一恒 on 2020/4/23.
// Q213、打家劫舍II
//

#include "util.h"

class Solution {
public:
    /**
     * 相比起问题1,该问题的区别在于第一个房子和最后一个房子只能偷1个
     * 那么我们分别计算不偷第一个房子的问题的解和不偷第二个房子的问题的解,取其中最大的那个即可
     */
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }
        int first = nums[0];
        nums.erase(nums.begin());
        int situation1 = dp_method(nums);
        nums.insert(nums.begin(), first);
        nums.erase(nums.begin() + nums.size() - 1);
        int situation2 = dp_method(nums);
        return max(situation1, situation2);
    }

    int dp_method(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int dp[nums.size()], i1, i2;
        for (int i = 0; i < nums.size(); i++) {
            i1 = (i - 1) >= 0 ? dp[i - 1] : 0;
            i2 = (i - 2) >= 0 ? dp[i - 2] : 0;
            dp[i] = max(i1, i2 + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};

