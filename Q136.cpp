//
// Created by 孙一恒 on 2020/1/27.
//
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * 方法1:可以看作是一种双指针的方法，使用O(1)的内存，但是时间复杂度高，为O(n^2)
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
     * 方法二:使用散列集合,将列表中的元素逐一的添加到集合中，如果集合中存在相同元素，则不添加并将那个元素移除,最后集合中剩下的那个元素即为所求,
     * 该方法的时间复杂度为O(n),空间复杂度也为O(n)
     * @param nums
     * @return
     */
    int singleNumber2(vector<int> &nums) {
        set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            int element = nums.at(i);
            // 如果集合中存在同样的元素,则移除
            if (set.find(element) != set.end()) {
                set.erase(element);
            } else {
                set.insert(element);
            }
        }
        return *set.begin();
    }

    /**
     * 方法三:如果有a、b、c三个元素，其中元素c仅出现一次，则所求的c = 2 * (a + b + c) - 整个列表的和。
     * 时间复杂度为O(n),空间复杂度为O(n)
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
     * 方法四：通过位运算来实现,对所有元素做异或运算得到的结果即为所求。
     * 时间复杂度O(n)，空间复杂度O(1) !!!
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
