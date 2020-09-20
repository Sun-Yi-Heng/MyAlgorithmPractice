//
// Created by ��һ�� on 2020/2/12.
// Q55����Ծ��Ϸ
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * ����1:���������뵽�ľ�����can_reach������������ܷ񵽴���Ӧλ��,Ȼ���ͷ��ʼ,һ�θ��ݿ�����Ծ�Ĳ�������Ӧλ������Ϊtrue��
     * �ύ����ʱ�临�Ӷȹ��ߡ����ܹ���n��λ�ã������µ�ʱ�临�Ӷ�ԼΪO(n^2)
     */
    bool canJump(vector<int>& nums) {
//        int total_steps = nums.size() - 1; // Ϊ�˴���������յ�,�����ܹ���Ҫ����ô�ಽ
        bool can_reach[nums.size()]; // can_reach�����ʾ�����ܷ񵽴�vector�еĵ�i��λ�á�
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
     * ����2:����̰���㷨,������������һ��λ��,һ��������ǰ���ÿһ��λ��(��Ϊnums[i]������������,������������С��λ��
     * ������k��¼����������Զλ��,��ͷ����nums�����ϸ���nums����kֵ,���k���ﲻ��n,�򷵻�false��������Ե���)
     * ֻ�����һ������,ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
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
      * ����3:���õݹ�,������֪���ܷ񵽴�λ��n,��ɨ��ǰ���λ��,���λ��i�ܵ���λ��n������ֻ����ȥ���ܷ񵽴�λ��i,ֱ���ҵ�λ��0Ϊֹ,ʱ�临�Ӷȹ���.
      * �����ύ����ֳ�ʱ����,�������뱸��¼,��¼���Ǽ����������,��ֹ�ظ����㡣
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
      * �жϴ�λ��0��ʼ�ܷ񵽴��±�Ϊdest��λ��
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