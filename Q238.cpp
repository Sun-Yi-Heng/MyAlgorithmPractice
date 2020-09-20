//
// Created by 孙一恒 on 2020/3/26.
// Q238、除自身以外数组的乘积
//

#include "util.h"

class Solution {
public:
    /**
     * 时间复杂度O(n),空间复杂度O(1),但是使用了除法
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        vector<int> result;
        vector<int> zero_index;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_index.push_back(i);
            } else {
                total *= nums[i];
            }
        }
        // 根据数组中0的个数区分处理情况
        if (zero_index.size() == 0) {
            for (int i = 0; i < nums.size(); i++) {
                result.push_back(total / nums[i]);
            }
        } else if (zero_index.size() == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (i == zero_index[0]) {
                    result.push_back(total);
                } else {
                    result.push_back(0);
                }
            }
        } else {
            for (int i = 0; i < nums.size(); i++) {
                result.push_back(0);
            }
        }
        return result;
    }

    /**
     * 计算该问题中的一个数，就需要我们得到其左侧所有数的乘积和其右侧所有数的乘积,然后乘在一起即可
     * 这只需要两次遍历即可完成，第一次计算左侧，第二次计算右侧，时间复杂度为O(N),空间复杂度O(1)
     */
    vector<int> productExceptSelf1(vector<int>& nums) {
        vector<int> result(nums.size());
        int currentLeft = 1;
        for (int i = 0; i < nums.size(); i++) {
            result[i] = currentLeft;
            currentLeft *= nums[i];
        }
        int currentRight = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] *= currentRight;
            currentRight *= nums[i];
        }
        return result;
    }
};

