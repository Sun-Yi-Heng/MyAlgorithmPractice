//
// Created by ��һ�� on 2020/7/6.
// Q15������֮��
//

#include "util.h"

class Solution {
public:
    /**
     * ˼·��Դ������"����֮��",���Ǳ������鲢�𲽼�¼�Ա������ֵ�����֮�ͺͶ�Ӧ��Ԫ��
     * ������������,�����������е�����֮������Ƿ��ܵõ�0,��¼���,����ɱȽϡ�
     * ʱ�临�Ӷ�ΪO(N^2),�ɾ������ݾ���
     * ������Ȼ��ʱ
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        // ����!����Ҫ,�����˺���ܶ�Ĺ���
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        unordered_map<int, vector<vector<int>>> tow_sum;
        // ���ڵ�i����,����������ǰ������������֮���Ƿ�������ӵ�0
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
            // �����µ�����֮��,ͨ���������������ʱ�临�Ӷ�
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
     * ˫ָ�뷨,ʱ�临�Ӷ�O(N^2),������
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
