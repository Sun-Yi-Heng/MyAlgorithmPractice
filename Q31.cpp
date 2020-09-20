/**
* 31����һ������
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * ��Ŀ����:ʲôʱ��һ����������������������? �����е�����������ݼ���
     * ʲôʱ��һ��������������������С��? �����е����������������
     * ��֪��ǰ���У�����ҵ���һ�������? ����Ѿ������ģ���������Ϊ��С�ģ�������ǣ�������ĩβ��ǰ���ң�ֱ���ҵ���һ���ƻ�����ݼ���Ԫ�أ�
     * ��������ĩβԪ�ؽ���,Ȼ����Ҫ�Ѻ����Ԫ�������������������,�Ա�֤��Ϊ��С��Ԫ��
     */
    void nextPermutation(vector<int>& nums) {
        int previous = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] >= previous) {
                previous = nums[i];
            } else {
                // �����ƻ�����ݼ���Ԫ��,�ҵ����������е�һ���������Ԫ��,���н����������i��Ԫ�غ������Ԫ��Ϊ����,Ȼ�󷵻�
                for (int j = nums.size() - 1; j >= 0; j--) {
                    if (nums[j] > nums[i]) {
                        swap(nums, j, i);
                        sort(nums, i + 1);
                        return;
                    }
                }
            }
        }
        // ��ȫ����:ֻ��Ҫ������vector����õ���С���м���
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
