//
// Created by ��һ�� on 2020/4/1.
// Q287��Ѱ���ظ���
//

#include "util.h"

class Solution {
public:
    /**
     * ����1:��ٱȽ�,ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O(n)
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
     * ����2:������,Ȼ�����,�ظ�Ԫ������������������
     * ʱ�临�Ӷȼ�Ϊ�����ʱ�临�Ӷ�O(nlgn),�ռ临�Ӷ��������ʵ�־���
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
     * ���ַ�:�۲���Ŀ���ǿ��Է���,������n+1������,���������ķ�Χ��1~n֮��,����,���ǿ��Զ��ظ����ķ�Χ���ж��ֲ���
     * ��1~n֮�������ظ�����Ҫlgn��,��ÿ�ζ���Ҫ����nums���м���(���ø볲ԭ��)
     * ʱ�临�Ӷ�O(nlgn),�ռ临�Ӷ�O(1),��ȫ������ĿҪ��
     */
    int findDuplicate2(vector<int> &nums) {
        // ��start��end����ֵ1��n
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
