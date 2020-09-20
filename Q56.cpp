//
// Created by 孙一恒 on 2020/2/14.
// Q56、合并区间
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 首先采取最笨的方法:逐一尝试合并
     * 直线上两个区间的三种情况:互斥/交叉/包含
     * 什么样的区间可以合并,[i1,j1]和[i2,j2]两个区间,如果i2 <= j1 <= j2或者 i1 <= j2 <= j1
     */
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        int deleted[intervals.size()];
//        vector<vector<int>> result;
//        for (int i = 0; i < intervals.size(); i++) {
//            if (deleted[i] == 1) {
//                continue;
//            }
//            for (int j = i + 1; j < intervals.size(); j++) {
//                if (deleted[j] == 1) {
//                    continue;
//                }
//                if (!(intervals[i][1] < intervals[j][0] || intervals[i][0] > intervals[j][1])) {
//                    intervals[i][0] = min(intervals[i][0], intervals[j][0]);
//                    intervals[i][1] = max(intervals[i][1], intervals[j][1]);
//                    deleted[j] = 1;
//                    j = i;
//                }
//            }
//        }
//        for (int i = 0; i < intervals.size(); i++) {
//            if (deleted[i] != 1) {
//                result.push_back(intervals[i]);
//            }
//        }
//        return result;
//    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return intervals;
        }
        int deleted[intervals.size()];
        for (int i = 0; i < intervals.size(); i++) {
            deleted[i] = -1;
        }
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++) {
            if (deleted[i] == 1) {
                continue;
            }
            for (int j = i + 1; j < intervals.size(); j++) {
                if (deleted[j] == 1) {
                    continue;
                }
                if (!(intervals[i][1] < intervals[j][0] || intervals[i][0] > intervals[j][1])) {
                    intervals[i][0] = min(intervals[i][0], intervals[j][0]);
                    intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                    deleted[j] = 1;
                    j = i;
                }
            }
        }
        for (int i = 0; i < intervals.size(); i++) {
            if (deleted[i] != 1) {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

int* test() {
    int* i = new int;
    return i;
}

//int main() {
//    vector<vector<int>> v;
//    vector<int> i = {1, 3};
//    v.push_back(i);
//    Solution s;
//    s.merge(v);
//}

