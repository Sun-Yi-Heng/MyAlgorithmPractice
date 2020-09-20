//
// Created by ��һ�� on 2020/3/16.
// 1������֮��
//

#include "util.h"

class Solution {
public:
    /**
     * ����1:���Ʒ���,ÿ�ν��б���,ʱ�临�Ӷ�ΪO(n^2),�ռ临�Ӷ�ΪO(1)
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
     * ������:����map,ʱ�临�Ӷȿ��Խ�ΪO(n),�ռ临�Ӷȴ���O(n)
     * �˴�����������
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
     * ����map�ļ򻯰汾!
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
     * ����3:����set
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




