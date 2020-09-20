//
// Created by ��һ�� on 2020/5/30.
// 793��ÿ���¶�
//

#include "util.h"

class Solution {
public:
    /**
     * ����1:������,����ÿһ��λ��,���Ƕ������������
     * ʱ�临�Ӷ�O(n^2)
     */
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result;
        result.resize(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            for (int j = i + 1; j < T.size(); j++) {
                if (T[j] > T[i]) {
                    result[i] = j - i;
                    break;
                }
            }
        }
        return result;
    }

    /**
     * ����2:���������Ļ�����,����һЩ�Ż�,��:�����������ִ��ڵ�����ǰ1������,�����ֱ�ӽ�����һ�����ֱȽϵ���λ��
     * �������бȽ�,��Ȼ��ʱ,�����µ�ʱ�临�Ӷ���δO(n^2)
     */
    vector<int> dailyTemperatures1(vector<int>& T) {
        vector<int> result;
        result.resize(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            if (i - 1 >= 0 && T[i] >= T[i - 1]) {
                for (int j = max(result[i - 1] + i - 1, i + 1); j < T.size(); j++) {
                    if (T[j] > T[i]) {
                        result[i] = j - i;
                        break;
                    }
                }
            }  else {
                for (int j = i + 1; j < T.size(); j++) {
                    if (T[j] > T[i]) {
                        result[i] = j - i;
                        break;
                    }
                }
            }
        }
        return result;
    }

    /**
     * ����3:������Ŀ�������¶ȵķ�Χ[30,100],����λ��i���¶�T[i],����ֻ��Ҫ�¶���(T[i], 100]֮��
     * ���±�ֵ����i���±�����С���Ǹ��±�j,���,���ǴӺ���ǰ����,������minIndex[t]��¼�¶�Ϊt�ĵ�ǰ��С�±�
     * ���ű����Ľ��в��ϸ���minIndex����
     * ʱ�临�Ӷ�ΪO(n * 70) (70Ϊ�¶ȵķ�Χ)
     */
    vector<int> dailyTemperatures3(vector<int>& T) {
        vector<int> result;
        vector<int> minIndex;
        result.resize(T.size(), 0);
        minIndex.resize(101, INT_MAX);
        for (int i = T.size() - 1; i >= 0; i--) {
            int j = INT_MAX;
            for (int t = T[i] + 1; t <= 100; t++) {
                j = min(j, minIndex[t]);
            }
            if (j != INT_MAX) {
                result[i] = j - i;
            }
            minIndex[T[i]] = i;
        }
        return result;
    }

    /**
     * ����4:��ԭ�㷨�����޸�,ʹ��ջ����¼��ǰ�����õ�Ԫ��
     * �������Ԫ�ش���ջ��Ԫ��,��popֱ��ջΪ�ղ�������Ӧresult���ߵ�ǰԪ��С�ڵ���ջ��Ԫ��
     * �������Ԫ��С�ڵ���ջ��Ԫ��,��ѹջ
     * �����ջ�е�Ԫ����Ӧλ��resultΪ0
     * ʱ�临�Ӷ�O(N)!
     */
    vector<int> dailyTemperatures2(vector<int>& T) {
        vector<int> result;
        if (T.size() == 0) {
            return result;
        }
        result.resize(T.size(), 0);
        stack<int> my_stack;
        for (int i = 0; i < T.size(); i++) {
            while (my_stack.size() != 0 && T[my_stack.top()] < T[i]) {
                int top_index = my_stack.top();
                my_stack.pop();
                result[top_index] = i - top_index;
            }
            my_stack.push(i);
        }
        while (my_stack.size() != 0 ) {
            int top_index = my_stack.top();
            my_stack.pop();
            result[top_index] = 0;
        }
        return result;
    }
};
