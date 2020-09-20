//
// Created by 孙一恒 on 2020/2/8.
// Q46、全排列
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    /**
     * 方法1:递归法
     */
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> init;
        solve(init, nums);
        return result;
    }

    void solve(vector<int> current, vector<int> remain) {
        if (remain.size() == 0) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < remain.size(); i++) {
            vector<int> new_current = current;
            new_current.push_back(remain[i]);
            vector<int> new_remain = remain;
            new_remain.erase(new_remain.begin() + i);
            solve(new_current, new_remain);
        }
    }
};
