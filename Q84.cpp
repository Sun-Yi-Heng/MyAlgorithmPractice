//
// Created by ��һ�� on 2020/2/23.
// Q84����״ͼ�����ľ���
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * ʹ��������̬�滮,��ǰ����𽥼������������,����ÿ�����ӣ�������Ľ�Ҫô������������ӣ�Ҫô��������ӵ�ǰ���ĳ������
     * ֮���������ӵõ��ģ���������������ҳ����п��ܵĽ⣬�Ӷ�ѡ�����ŵ��Ǹ���
     * ����ѭ����ʱ�临�Ӷ�ΪO(n ^ 3)���ռ临�Ӷ�O(1), �ύ���ֳ�ʱ
     */
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            // ������������,��ǰ�������������ɴ�i��ʼ����ǰ������������������ɵ�,������ɵľ��ε����=(i - j + 1) * minHeight
            for (int j = i; j >= 0; j--) {
                int minHeight = heights[j];
                for (int k = j; k <= i; k++) {
                    minHeight = min(minHeight, heights[k]);
                }
                int currentArea = minHeight * (i - j + 1);
                largestArea = max(largestArea, currentArea);
            }
        }
        return largestArea;
    }

    /**
     * �Ż������������,�������ڲ�ѭ��,�����ö�ά�����¼�´�λ��i��λ��j֮������ӵ���С�߶�
     * ʱ�临�Ӷ�ΪO(n ^ 2), �ռ临�Ӷ�ΪO(n ^ 2)
     **/
    int largestRectangleArea1(vector<int>& heights) {
        int largestArea = 0;
        if (heights.size() == 0) {
            return 0;
        }
        int height[heights.size()][heights.size()];
        for (int i = 0; i < heights.size(); i++) {
            // ������������,��ǰ�������������ɴ�i��ʼ����ǰ������������������ɵ�,������ɵľ��ε����=(i - j + 1) * minHeight
            for (int j = i; j >= 0; j--) {
                int minHeight;
                if (j == i) {
                    minHeight = heights[i];
                    height[j][i] = heights[i];
                } else {
                    minHeight = min(height[j][i - 1], heights[i]);
                    height[j][i] = minHeight;
                }
                int currentArea = minHeight * (i - j + 1);
                largestArea = max(largestArea, currentArea);
            }
        }
        return largestArea;
    }


    /**
     * ���Ƿ�����ȫû�б�Ҫ�ö�ά�����¼�¸����������С�߶�,ֱ���ڵڶ���ѭ����ʱ��˳�����㼴��
     * ʱ�临�Ӷ�ΪO(n ^ 2), �ռ临�Ӷ�O(1)����Ȼ��ʱ
     * @return
     */
    int largestRectangleArea2(vector<int>& heights) {
        int largestArea = 0;
        if (heights.size() == 0) {
            return 0;
        }
        for (int i = 0; i < heights.size(); i++) {
            // ������������,��ǰ�������������ɴ�i��ʼ����ǰ������������������ɵ�,������ɵľ��ε����=(i - j + 1) * minHeight
            int minHeight = heights[i];
            for (int j = i; j >= 0; j--) {
                minHeight = min(heights[j], minHeight);
                int currentArea = minHeight * (i - j + 1);
                largestArea = max(largestArea, currentArea);
            }
        }
        return largestArea;
    }

    /**
     * ���÷��η����
     */


    /**
     * ����ջ�ṹ,�������ұ�����������,�����ǰԪ��>=ջ��Ԫ��,����ѹ��ջ��,����,����ջ������������ջ��ʣ��Ԫ��һ�ε���
     * ��Ԫ�ص���ʱ,���ǾͿ��Լ����Ե�ǰԪ�ظ߶Ⱦ����ľ������,Ϊ�ˣ�����Ҫȷ�����ұ߽�,��������ұ߽羿����ʲô�ǽ�������Ĺؼ�
     */
    int largestRectangleArea5(vector<int>& heights) {
        if (heights.size() == 0) {
            return 0;
        }
        int maxArea = 0;
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            if (s.size() == 0 || heights[s.top()] <= heights[i]) {
                s.push(i);
            } else {
                int rightIndex = i;
                while (s.size() != 0 && heights[s.top()] > heights[i]) {
                    int index = s.top();
                    s.pop();
                    int currentArea = 0;
                    if (s.size() == 0) {
                        currentArea = (rightIndex - 0) * heights[index];
                    } else {
                        currentArea = (rightIndex - s.top() - 1) * heights[index];
                    }
                    maxArea = max(maxArea, currentArea);
                }
                s.push(i);
            }
        }
        int rightIndex = s.top();
        // �����whileѭ����forѭ���еĲ�ͬ
        while (s.size() != 1) {
            int index = s.top();
            s.pop();
            int currentArea = (rightIndex - s.top()) * heights[index];
            maxArea = max(maxArea, currentArea);
        }
        int currentArea = heights.size() * heights[s.top()];
        maxArea = max(maxArea, currentArea);
        return maxArea;
    }
};