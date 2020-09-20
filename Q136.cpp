//
// Created by ��һ�� on 2020/1/27.
//
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * ����1:���Կ�����һ��˫ָ��ķ�����ʹ��O(1)���ڴ棬����ʱ�临�Ӷȸߣ�ΪO(n^2)
     * @param nums
     * @return
     */
    int singleNumber1(vector<int>& nums) {
        int pointer1 = 0;
        int pointer2 = 0;
        while (pointer2 != nums.size())
        {
            if (nums.at(pointer2) == nums.at(pointer1) && pointer2 != pointer1)
            {
                pointer1++;
                pointer2 = 0;
            } else {
                pointer2++;
            }
        }
        return nums.at(pointer1);
    }

    /**
     * ������:ʹ��ɢ�м���,���б��е�Ԫ����һ����ӵ������У���������д�����ͬԪ�أ�����Ӳ����Ǹ�Ԫ���Ƴ�,��󼯺���ʣ�µ��Ǹ�Ԫ�ؼ�Ϊ����,
     * �÷�����ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ҲΪO(n)
     * @param nums
     * @return
     */
    int singleNumber2(vector<int> &nums) {
        set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            int element = nums.at(i);
            // ��������д���ͬ����Ԫ��,���Ƴ�
            if (set.find(element) != set.end()) {
                set.erase(element);
            } else {
                set.insert(element);
            }
        }
        return *set.begin();
    }

    /**
     * ������:�����a��b��c����Ԫ�أ�����Ԫ��c������һ�Σ��������c = 2 * (a + b + c) - �����б�ĺ͡�
     * ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(n)
     */
     int singleNumber3(vector<int> &nums) {
         int sum = 0;
         int total = 0;
         int temp;
         set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            temp = nums.at(i);
            if (set.find(temp) != set.end()) {
                total += temp;
                set.insert(temp);
            }
            sum += temp;
        }
        return 2 * total - sum;
     }

    /**
     * �����ģ�ͨ��λ������ʵ��,������Ԫ�����������õ��Ľ����Ϊ����
     * ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1) !!!
     */
    int singleNumber4(vector<int> &nums)
    {
        int result = nums.at(0);
        for (int i = 1; i < nums.size(); i++) {
            result ^= nums.at(i);
        }
        return result;
    }
};
