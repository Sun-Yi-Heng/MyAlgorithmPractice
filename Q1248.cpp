//
// Created by 孙一恒 on 2020/5/25.
// Q1248、优美子数组
//
#include "util.h"

class Solution {
public:
    /**
     * 仿照Q560的解法,该算法的时间复杂度为O(n)
     * 使用前缀数来解决
     */
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> num_times_map;
        num_times_map[0] = 1;
        int current_odd_number = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                current_odd_number++;
            }
            result += num_times_map[current_odd_number - k];
            num_times_map[current_odd_number]++;
        }
        return result;
    }

    /**
     * 相比起方法1:由于map中的键值一定在0 ~ nums.size之间,因此直接用数组来代替map更加高效.
     * 同时,使用位运算可以简化求余运算
     */
    int numberOfSubarrays1(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = 0;
        vector<int> num_times;
        num_times.resize(nums.size() + 1, 0);
        num_times[0] = 1;
        int current_odd_number = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & 1) == 1) {
                current_odd_number++;
            }
            if (current_odd_number - k >= 0) {
                result += num_times[current_odd_number - k];
            }
            num_times[current_odd_number]++;
        }
        return result;
    }
};

