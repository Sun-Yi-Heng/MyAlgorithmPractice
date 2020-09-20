/**
* 31、下一个序列
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 题目分析:什么时候一个排列是所有排列中最大的? 当其中的数字是有序递减的
     * 什么时候一个排列是所有排列中最小的? 当其中的数字是有序递增的
     * 已知当前序列，如何找到下一大的序列? 如果已经是最大的，将其逆序为最小的，如果不是，从序列末尾往前查找，直到找到第一个破坏有序递减的元素，
     * 将其与最末尾元素交换,然后还需要把后面的元素重新排序有序递增的,以保证其为次小的元素
     */
    void nextPermutation(vector<int>& nums) {
        int previous = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] >= previous) {
                previous = nums[i];
            } else {
                // 发现破坏有序递减的元素,找到后面序列中第一个比它大的元素,进行交换、排序第i个元素后的所有元素为递增,然后返回
                for (int j = nums.size() - 1; j >= 0; j--) {
                    if (nums[j] > nums[i]) {
                        swap(nums, j, i);
                        sort(nums, i + 1);
                        return;
                    }
                }
            }
        }
        // 完全有序:只需要将整个vector逆序得到最小序列即可
        for (int i = 0; i < nums.size() / 2; i++) {
            swap(nums, i, nums.size() - i - 1);
        }
    }

    void swap(vector<int>& nums, int p1, int p2) {
        int temp = nums[p1];
        nums[p1] = nums[p2];
        nums[p2] = temp;
    }

    void sort(vector<int> &nums, int start) {
        for (int i = start; i < nums.size(); i++) {
            for (int j = start; j < nums.size() - i + start - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums, j, j + 1);
                }
            }
        }
    }
};
