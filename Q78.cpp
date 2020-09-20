//
// Created by 孙一恒 on 2020/2/20.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    /**
     * 通过递归的回溯算法解决问题,求所有子集恰好就对应着我们的子集树。
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
     * 方法2:我们不难注意到,已知n个元素的全部子集,新来一个元素,这n+1个元素对应的全部子集 = n个元素子集  + （n个元素子集 + 第n+1个元素)
     * ,直接用迭代的方法就可以解决。
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
     * 和方法1中所想的一样，我们认为每个元素有取或者不取两种可能，n个元素对应的子集数量为2^n,恰好对应了n位2进制数对应的编码数量
     * 这2^n个编码就是我们子集树叶子节点对应的取值,我们直接进行解析既可。
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
