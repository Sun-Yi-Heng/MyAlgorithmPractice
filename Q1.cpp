//
// Created by 孙一恒 on 2020/3/16.
// 1、两数之和
//

#include "util.h"

class Solution {
public:
    /**
     * 方法1:笨逼方法,每次进行遍历,时间复杂度为O(n^2),空间复杂度为O(1)
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] + nums[i] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }

    /**
     * 方法二:利用map,时间复杂度可以将为O(n),空间复杂度大于O(n)
     * 此处画蛇添足了
     */
    vector<int> twoSum1(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> val_index_map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            auto find_result = val_index_map.find(nums[i]);
            if (find_result == val_index_map.end()) {
                vector<int> indexes = {i};
                val_index_map[nums[i]] = indexes;
            } else {
                val_index_map[nums[i]].push_back(i);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            auto find_result = val_index_map.find(target - nums[i]);
            if (target - nums[i] == nums[i]) {
                if (find_result != val_index_map.end() && find_result->second.size() == 2) {
                    return find_result->second;
                }
            } else {
                if (find_result != val_index_map.end()) {
                    result.push_back(i);
                    result.push_back(find_result->second[0]);
                    return result;
                }
            }
        }
        return result;
    }

    /**
     * 利用map的简化版本!
     */
    vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> num_index_map;
        for (int i = 0; i < nums.size(); i++) {
            auto find_result = num_index_map.find(target - nums[i]);
            if (find_result != num_index_map.end()) {
                result.push_back(find_result->second);
                result.push_back(i);
            } else {
                num_index_map[nums[i]] = i;
            }
        }
        return result;
    }

    /**
     * 方法3:利用set
     * @param nums
     * @param target
     * @return
     */
    vector<int> twoSum3(vector<int>& nums, int target) {
        unordered_set<int> val_set;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            val_set.insert(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            auto find_result = val_set.find(target - nums[i]);
            if (find_result != val_set.end()) {
                for (int j = 0; j < nums.size(); j++) {
                    if (j != i && nums[j] + nums[i] == target) {
                        result.push_back(i);
                        result.push_back(j);
                        return result;
                    }
                }
            }
        }
        return result;
    }
};




