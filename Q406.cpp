//
// Created by ��һ�� on 2020/5/18.
// Q406����Ϣ�Ĵ������ʾ
//
#include "util.h"

class Solution {
public:
    /**
     * ����ĳһ��ߵ�����˵,��kֵ������ߴ��ڻ���������˾�����
     * ���,�����ȶ������ߵ�������,Ȼ������ߴθߵ�...�������λ�þ�����kֵ��λ�ã����룩
     * (��Ϊ��ߵ͵����ڶ����еĲ���,�������ƻ��Ѿ��źõ���߸ߵ���)
     * �����漰������,���㷨��ʱ�临�Ӷ�ΪO(nlgn),�ռ临�Ӷ�ΪO(n)
     */
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        // �Ȱ�����߽�������
        sort(people.begin(), people.end(), myCompare_height);
        // ����ͬһ��ߵ�,����index����������
        for (int i = 0; i < people.size(); i++) {
            int current_height = people[i][0];
            int j = i;
            while (j < people.size() && people[j][0] == current_height) {
                j++;
            }
            sort(people.begin() + i, people.begin() + j, myCompare_index);
            i = j - 1;
        }
        // ֮��,ֻ��Ҫ��������insert�������ɡ�
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

