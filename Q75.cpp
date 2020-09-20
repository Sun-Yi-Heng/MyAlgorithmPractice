//
// Created by 孙一恒 on 2020/2/18.
// Q75、颜色分类
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * 方法1:两趟扫描,第一趟统计各个颜色的数量,第二趟直接赋值即可.
     * @param nums
     */
    void sortColors(vector<int>& nums) {
        int num[3];
        num[0] = 0;
        num[1] = 0;
        num[2] = 0;
        for (int i = 0; i < nums.size(); i++) {
            num[nums[i]]++;
        }
        for (int i = 0; i < 3; i++) {
            int bias = 0;
            for (int k = 0; k < i; k++) {
                bias += num[k];
            }
            for (int j = 0; j < num[i]; j++) {
                nums[j + bias] = i;
            }
        }
    }

    /**
     * 方法2:一趟扫描解决问题,尝试通过双指针解决问题
     */
    void sortColors1(vector<int>& nums) {
        // p0为0的最右边界,而p2为2的最左边界,i为当前考虑的元素
        int p0 = 0, p2 = nums.size() - 1;
        for (int i = 0; i <= p2; i++) {
            if (nums[i] == 0) {
                swap(nums, i, p0);
                p0++;
            } else if (nums[i] == 2) {
                swap(nums, i, p2);
                p2--;
                // 由于不确定换过来的是个什么,所以i--,对当前位置再判断一次。
                i--;
            }
        }
   }

   void swap(vector<int>& nums, int i1, int i2) {
        int temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
    }
};

