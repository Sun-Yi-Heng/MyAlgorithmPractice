//
// Created by 孙一恒 on 2020/2/12.
// Q55、跳跃游戏
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 方法1:我们最先想到的就是用can_reach数组代表我们能否到达相应位置,然后从头开始,一次根据可以跳跃的步数将相应位置设置为true。
     * 提交后发现时间复杂度过高。若总共有n个位置，最坏情况下的时间复杂度约为O(n^2)
     */
    bool canJump(vector<int>& nums) {
//        int total_steps = nums.size() - 1; // 为了从起点跳到终点,我们总共需要跳这么多步
        bool can_reach[nums.size()]; // can_reach数组表示我们能否到达vector中的第i个位置。
        can_reach[0] = true;
        for (int i = 1; i < nums.size(); i++) {
            can_reach[i] = false;
        }
        for (int i = 0; i < nums.size() && !can_reach[nums.size() - 1]; i++) {
            if (can_reach[i]) {
                for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
                    can_reach[i + j] = true;
                }
            }
        }
        return can_reach[nums.size() - 1];
    }

    /**
     * 方法2:采用贪心算法,如果能跳到最后一个位置,一定能跳到前面的每一个位置(因为nums[i]代表的是最大步数,可以跳到比其小的位置
     * 我们用k记录能跳到的最远位置,从头遍历nums，不断根据nums更新k值,如果k到达不了n,则返回false，否则可以到达)
     * 只需遍历一遍数组,时间复杂度为O(n)，空间复杂度为O(1)
     */
     bool canJump1(vector<int>& nums) {
         int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                return false;
            }
            k = max(k, i + nums[i]);
        }
        return true;
     }

     /**
      * 方法3:利用递归,我们想知道能否到达位置n,则扫描前面的位置,如果位置i能到达位置n，我们只需再去找能否到达位置i,直到找到位置0为止,时间复杂度过高.
      * 由于提交后出现超时问题,我们引入备忘录,记录我们计算过的问题,防止重复计算。
      */
     bool canJump2(vector<int>& nums) {
         if (nums.size() == 1) {
             return true;
         }
         int memo[nums.size()];
         for (int i = 0; i < nums.size(); i++) {
             memo[i] = 0;
         }
         return canReach(nums.size() - 1, nums, memo);
     }

     /**
      * 判断从位置0开始能否到达下标为dest的位置
      */
     bool canReach(int dest, vector<int>& nums, int memo[]) {
         if (memo[dest] == 1) {
             return true;
         }
         if (memo[dest] == -1) {
             return false;
         }
         for (int i = 0; i < dest; i++) {
             if (nums[i] >= dest - i) {
                 if (i == 0) {
                     memo[dest] = 1;
                     return true;
                 } else {
                     if (canReach(i, nums, memo)) {
                         memo[dest] = 1;
                         return true;
                     }
                 }
             }
         }
         memo[dest] = -1;
         return false;
     }
};