//
// Created by ��һ�� on 2020/3/28.
// Q4��Ѱ�����������������λ��
// �ο���https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
//

#include "util.h"

class Solution {
public:
    /**
     * ����nums1��nums2,�������ܻ�ȡ����Ϣ�������Ǹ��Եĳ���m��n
     * ����,����ֻ��Ҫ����˳���������,�ҵ���Ӧλ��Ԫ�ؼ���
     * ʱ�临�Ӷ�O(M + N), �ռ临�Ӷ�O(1)
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
     * ����2:������ת��Ϊ��õ�kС������
     * ���ڻ�ȡ��kС�����ֿ�����logʱ�临�Ӷ��ڽ��,����ԭ����Ҳ������logʱ�临�Ӷ������
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
     * ����nums1��nums2�ϲ������е�kС������
     */
    int getKth(int k, int start1, int end1, vector<int>& nums1, int start2, int end2, vector<int>& nums2) {
        // ���㵱ǰnums1��nums2����ʣ��ĳ���
        int length1 = end1 - start1 + 1;
        int length2 = end2 - start2 + 1;
        // ���ǽ���nums1�п��ܳ���Ϊ0
        if (length2 == 0) {
            return getKth(k, start2, end2, nums2, start1, end1, nums1);
        }
        // ���nums1��ʣ�೤��Ϊ0
        if (length1 == 0) {
            return nums2[start2 + k - 1];
        }
        // ��k = 1��ʱ��,ֱ�ӷ�����С����,��Ȼ�������index��ʱ��,����ֱ�start��С�����.
        if (k == 1) {
            return min(start1 <= end1 ? nums1[start1] : INT_MAX, start2 <= end2 ? nums2[start2] : INT_MAX);
        }
        // ����Ƚ�nums1��nums2�ĵ�k/2�����Ĵ�С,��ɾ����С����һ��
        int index1 = (start1 + k / 2 - 1) > end1 ? end1 : (start1 + k / 2 - 1);
        int index2 = (start2 + k / 2 - 1) > end2 ? end2 : (start2 + k / 2 - 1);
        if (nums1[index1] > nums2[index2]) {
            return getKth(k - (index2 - start2 + 1), start1, end1, nums1, index2 + 1, end2, nums2);
        } else {
            return getKth(k - (index1 - start1 + 1), index1 + 1, end1, nums1, start2, end2, nums2);
        }
    }
};