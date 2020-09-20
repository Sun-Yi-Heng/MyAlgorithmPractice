//
// Created by ��һ�� on 2020/2/20.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    /**
     * ͨ���ݹ�Ļ����㷨�������,�������Ӽ�ǡ�þͶ�Ӧ�����ǵ��Ӽ�����
     */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> init;
        recursion(0, init, nums);
        return result;
    }

    void recursion(int position, vector<int> current, vector<int>& nums) {
        if (position == nums.size()) {
            result.push_back(current);
        } else {
            recursion(position + 1, current, nums);
            current.push_back(nums[position]);
            recursion(position + 1, current, nums);
        }
    }

    /**
     * ����2:���ǲ���ע�⵽,��֪n��Ԫ�ص�ȫ���Ӽ�,����һ��Ԫ��,��n+1��Ԫ�ض�Ӧ��ȫ���Ӽ� = n��Ԫ���Ӽ�  + ��n��Ԫ���Ӽ� + ��n+1��Ԫ��)
     * ,ֱ���õ����ķ����Ϳ��Խ����
     */
    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<vector<int>> r;
        vector<int> empty;
        r.push_back(empty);
        for (int i = 0; i < nums.size(); i++) {
            int current_length = r.size();
            for (int j = 0; j < current_length; j++) {
                vector<int> old = r[j];
                old.push_back(nums[j]);
                r.push_back(old);
            }
        }
        return r;
    }

    /**
     * �ͷ���1�������һ����������Ϊÿ��Ԫ����ȡ���߲�ȡ���ֿ��ܣ�n��Ԫ�ض�Ӧ���Ӽ�����Ϊ2^n,ǡ�ö�Ӧ��nλ2��������Ӧ�ı�������
     * ��2^n��������������Ӽ���Ҷ�ӽڵ��Ӧ��ȡֵ,����ֱ�ӽ��н����ȿɡ�
     */
    vector<vector<int>> subsets2(vector<int>& nums) {
        vector<vector<int>> r;
        int size = nums.size();
        for (int i = 0; i < (1 << size); i++) {
            vector<int> element;
            for (int j = 0; j < size; j++) {
                if (((i >> j) & 1) == 1) {
                    element.push_back(nums[j]);
                }
            }
            r.push_back(element);
        }
        return r;
    }
};
