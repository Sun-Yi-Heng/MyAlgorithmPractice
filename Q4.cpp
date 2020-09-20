//
// Created by 孙一恒 on 2020/3/28.
// Q4、寻找两个有序数组的中位数
// 参考：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
//

#include "util.h"

class Solution {
public:
    /**
     * 对于nums1和nums2,我们所能获取的信息就是它们各自的长度m和n
     * 所以,我们只需要按照顺序遍历数组,找到相应位置元素即可
     * 时间复杂度O(M + N), 空间复杂度O(1)
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length = nums1.size() + nums2.size();
        double result = 0;
        int index1 = 0, index2 = 0;
        int left = 0, right = 0;
        while ((index1 + index2) < (length / 2 + 1)) {
            left = right;
            if (index1 < nums1.size() && (index2 >= nums2.size() || nums1[index1] < nums2[index2])) {
                right = nums1[index1++];
            } else {
                right = nums2[index2++];
            }
        }
        if ((length & 2) == 0) {
            return (double)(left + right) / 2;
        } else {
            return left;
        }
    }


    /**
     * 方法2:把问题转化为获得第k小数问题
     * 由于获取第k小的数字可以在log时间复杂度内解决,所以原问题也可以在log时间复杂度内求解
     */
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        int length = nums1.size() + nums2.size();
        if ((length & 1) == 0) {
            return (double)(getKth((length + 1) / 2, 0, nums1.size() - 1, nums1, 0, nums2.size() - 1, nums2) + getKth((length + 2) / 2, 0, nums1.size() - 1, nums1, 0, nums2.size() - 1, nums2)) / 2;
        } else {
            return getKth((length + 1) / 2, 0, nums1.size() - 1, nums1, 0, nums2.size() - 1, nums2);
        }
    }

    /**
     * 返回nums1和nums2合并后其中第k小的数字
     */
    int getKth(int k, int start1, int end1, vector<int>& nums1, int start2, int end2, vector<int>& nums2) {
        // 计算当前nums1和nums2各自剩余的长度
        int length1 = end1 - start1 + 1;
        int length2 = end2 - start2 + 1;
        // 我们仅令nums1有可能长度为0
        if (length2 == 0) {
            return getKth(k, start2, end2, nums2, start1, end1, nums1);
        }
        // 如果nums1的剩余长度为0
        if (length1 == 0) {
            return nums2[start2 + k - 1];
        }
        // 当k = 1的时候,直接返回最小的数,不然下面计算index的时候,会出现比start还小的情况.
        if (k == 1) {
            return min(start1 <= end1 ? nums1[start1] : INT_MAX, start2 <= end2 ? nums2[start2] : INT_MAX);
        }
        // 否则比较nums1和nums2的第k/2个数的大小,并删除较小的那一方
        int index1 = (start1 + k / 2 - 1) > end1 ? end1 : (start1 + k / 2 - 1);
        int index2 = (start2 + k / 2 - 1) > end2 ? end2 : (start2 + k / 2 - 1);
        if (nums1[index1] > nums2[index2]) {
            return getKth(k - (index2 - start2 + 1), start1, end1, nums1, index2 + 1, end2, nums2);
        } else {
            return getKth(k - (index1 - start1 + 1), index1 + 1, end1, nums1, start2, end2, nums2);
        }
    }
};