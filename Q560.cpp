//
// Created by 孙一恒 on 2020/5/24.
// Q560、和为K的子数组
//
#include "util.h"

class Solution {
public:
    /**
     * 方法1:首先使用笨逼方法:通过遍历求所有子数组的和,判断其是否等于K,最终返回计数器的计数结果
     * 时间复杂度为O(n^2)显然超时
     */
    int subarraySum(vector<int>& nums, int k) {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (k == sum) {
                    counter++;
                }
            }
        }
        return counter;
    }

    /**
     * 方法2:使用前缀和,设preSum[i] 代表着从nums[0]到nums[i - 1]所有元素的和
     * 这样(i和j之间的子数组和) = preSum[j + 1] - preSum[i]
     * 该算法的时间复杂度仍未O(n^2),但是用到的思想更加巧妙
     */
    int subarraySum1(vector<int>& nums, int k) {
        int counter = 0;
        int preSum[nums.size() + 1];
        preSum[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (preSum[j + 1] - preSum[i] == k) {
                    counter++;
                }
            }
        }
        return counter;
    }

    /**
     * 方法3:利用上面前缀和的思想,利用哈希表保存前缀和的出现次数
     * 当计算到某一前缀和时，我们通过哈希表可以直接确定前面有多少的前缀和满足 “当前前缀和” - “前面前缀和” == k
     * 这样,该算法的时间复杂度将为O(N)
     * 注意这里map的使用方式...(为啥没有插入的元素也可以直接++呀。。。）
     */
    int subarraySum2(vector<int>& nums, int k) {
        int counter = 0;
        int pre = 0;
        unordered_map<int, int> preSum_times;
        preSum_times[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            auto find_result = preSum_times.find(pre - k);
            counter += find_result == preSum_times.end() ? 0 : find_result->second;
            preSum_times[pre]++;
        }
        return counter;
    }
};

