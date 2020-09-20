//
// Created by 孙一恒 on 2020/5/21.
// Q448、找到所有数组中消失的数字
//
#include "util.h"

class Solution {
public:
    /**
     * 方法1:对数组进行排序,然后扫描一遍数组即可知道缺少哪些元素了
     * 算法的时间复杂度O(nlgn)(由排序算法决定), 算法的空间复杂度为O(1)
     */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int current_num = 1; // 从1开始比较,统计没有出现过的数字
        for (int i = 0; i < nums.size(); i++) {
            if (current_num == nums[i]) {
                current_num++;
            } else if (current_num < nums[i]) {
                while (current_num < nums[i]) {
                    result.push_back(current_num);
                    current_num++;
                }
                current_num++;
            }
        }
        while (current_num <= nums.size()) {
            result.push_back(current_num);
            current_num++;
        }
        return result;
    }

    /**
     * 方法2:申请一个长度为nums[size]的bool数组,对其进行遍历,如果访问过就设置为true
     * 该算法的时间复杂度为O(N),空间复杂度也为O(N)
     */
    vector<int> findDisappearedNumbers1(vector<int>& nums) {
        vector<int> result;
        if (nums.size() == 0) {
            return result;
        }
        bool have[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            have[i] = false;
        }
        for (int i = 0; i < nums.size(); i++) {
            have[nums[i] - 1] = true;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!have[i]) {
                result.push_back(i + 1);
            }
        }
        return result;
    }

    /**
     * 方法3:直接在nums上改变,算法的思想和方法2一致,虽然时间复杂度为O(N),空间复杂度为O(1),但是因为修改了原数组
     * 因此不能算是满足要求。
     */
    vector<int> findDisappearedNumbers2(vector<int>& nums) {
        vector<int> result;
        int index = 0;
        while (index != nums.size()) {
            if (nums[index] == -1) {
                index++;
            } else {
                int temp = nums[index];
                if (nums[nums[index] - 1] != -1) {
                    nums[index] = nums[nums[index] - 1];
                } else {
                    index++;
                }
                nums[temp - 1] = -1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != -1) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
