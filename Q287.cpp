//
// Created by 孙一恒 on 2020/4/1.
// Q287、寻找重复数
//

#include "util.h"

class Solution {
public:
    /**
     * 方法1:穷举比较,时间复杂度O(n^2),空间复杂度O(n)
     */
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    nums[i];
                }
            }
        }
        return -1;
    }

    /**
     * 方法2:先排序,然后遍历,重复元素在排序后的数组相邻
     * 时间复杂度即为排序的时间复杂度O(nlgn),空间复杂度由排序的实现决定
     */
    int findDuplicate1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        return -1;
    }

    /**
     * 二分法:观察题目我们可以发现,给出的n+1个数中,限制了数的范围在1~n之间,这样,我们可以对重复数的范围进行二分查找
     * 在1~n之间锁定重复数需要lgn次,而每次都需要遍历nums进行计数(利用鸽巢原理)
     * 时间复杂度O(nlgn),空间复杂度O(1),完全满足题目要求
     */
    int findDuplicate2(vector<int> &nums) {
        // 将start和end赋初值1和n
        int start = 1;
        int end = nums.size() - 1;
        int middle = (start + end) / 2;
        while (start < end) {
            middle = (start + end) / 2;
            int counter = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (start <= nums[i] && nums[i] <= middle) {
                    counter++;
                }
            }
            if (counter > (middle - start + 1)) {
                end = middle;
            } else {
                start = middle + 1;
            }
        }
        return start;
    }
};
