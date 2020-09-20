//
// Created by 孙一恒 on 2020/5/18.
// Q406、信息的处理与表示
//
#include "util.h"

class Solution {
public:
    /**
     * 对于某一身高的人来说,其k值仅由身高大于或等于他的人决定。
     * 因此,我们先对身高最高的人排序,然后拍身高次高的...而排序的位置就是其k值的位置（插入）
     * (因为身高低的人在队列中的插入,并不会破坏已经排好的身高高的人)
     * 由于涉及到排序,该算法的时间复杂度为O(nlgn),空间复杂度为O(n)
     */
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        // 先按照身高降序排序
        sort(people.begin(), people.end(), myCompare_height);
        // 对于同一身高的,按照index再升序排序
        for (int i = 0; i < people.size(); i++) {
            int current_height = people[i][0];
            int j = i;
            while (j < people.size() && people[j][0] == current_height) {
                j++;
            }
            sort(people.begin() + i, people.begin() + j, myCompare_index);
            i = j - 1;
        }
        // 之后,只需要挨个进行insert操作即可。
        for (int i = 0; i < people.size(); i++) {
            result.insert(result.begin() + people[i][1], people[i]);
        }
        return result;
    }

    static bool myCompare_height(vector<int> v1, vector<int> v2) {
        return v1[0] > v2[0];
    }

    static bool myCompare_index(vector<int> v1, vector<int> v2) {
        return v1[1] < v2[1];
    }
};

