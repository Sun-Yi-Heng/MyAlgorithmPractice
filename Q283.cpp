//
// Created by ÀÔ“ª∫„ on 2020/3/31.
// Q283°¢“∆∂Ø¡„
//
#include "util.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int front = 0, zero_num = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_num++;
            } else {
                nums[front++] = nums[i];
            }
        }
        for (int i = 0; i < zero_num; i++) {
            nums[nums.size() - i - 1] = 0;
        }
    }

    void moveZeroes1(vector<int>& nums) {
        int lastNoneZero = 0, temp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                temp = nums[i];
                nums[i] = nums[lastNoneZero];
                nums[lastNoneZero] = temp;
                lastNoneZero++;
            }
        }
    }
};

