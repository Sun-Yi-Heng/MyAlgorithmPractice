//
// Created by 孙一恒 on 2020/7/6.
// Q15、三数之和
//

#include "util.h"

class Solution {
public:
    /**
     * 思路来源与问题"两数之和",我们遍历数组并逐步记录以遍历部分的两数之和和对应的元素
     * 对于新来的数,计算其与已有的两数之和相加是否能得到0,记录结果,并完成比较。
     * 时间复杂度为O(N^2),由具体数据决定
     * 但是仍然超时
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 排序!很重要,方便了后面很多的工作
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        unordered_map<int, vector<vector<int>>> tow_sum;
        // 对于第i个数,我们找其与前面计算过的两数之和是否满足相加得0
        for (int i = 0; i < nums.size(); i++) {
            auto find_result = tow_sum.find(-nums[i]);
            if (find_result != tow_sum.end()) {
                for (vector<int> v : find_result->second) {
                    vector<int> prob_solve = {v[0], v[1], nums[i]};
                    bool flag = true;
                    for (vector<int> r : result) {
                        if (r == prob_solve) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        result.push_back(prob_solve);
                    }
                }
            }
            // 计算新的两数之和,通过划分情况来降低时间复杂度
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                if (i - 2 >= 0 && nums[i - 1] == nums[i - 2]) {

                } else {
                    vector<int> current;
                    current.push_back(nums[i]);
                    current.push_back(nums[i]);
                    tow_sum[nums[i] + nums[i]].push_back(current);
                }
            } else {
                for (int j = 0; j < i; j++) {
                    vector<int> current;
                    current.push_back(nums[j]);
                    current.push_back(nums[i]);
                    tow_sum[nums[i] + nums[j]].push_back(current);
                }
            }
        }
        return result;
    }

    /**
     * 双指针法,时间复杂度O(N^2),简单明了
     * https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/
     */
    vector<vector<int>> threeSum1(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int right = nums.size() - 1;
            int left = i + 1;
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                if (current_sum > 0) {
                    right--;
                } else if (current_sum < 0) {
                    left++;
                } else {
                    vector<int> r = {nums[i], nums[left], nums[right]};
                    result.push_back(r);
                    left++;
                    while (left < nums.size() && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
