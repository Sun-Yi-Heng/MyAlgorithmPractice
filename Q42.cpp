//
// Created by ��һ�� on 2020/2/5.
// Q42������ˮ
//

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * �۲�ͼ��,��֪������Ҫ�������һ��������ʢ����ˮ������,Ϊ��������Ҫ���μ���ÿ���������߽���ұ߽�
     * һ��ʼ���������Ϊ��߽�,0��Ȼ������Ϊ��߽�,�����ǰ��߽�Ľ��ڵ���һ�����Ӹ���,��ȻӦ�ý���һ��������Ϊ��߽�
     * ��߽�ȷ����,��������ұ߽�:���ҵ����ڻ������߽������ʱ,����ȷ����Ϊ�ұ߽硣����Ҳ��������Ҳ�Ҳ�������������,��������ߵ��Ǹ���Ϊ�ұ߽硣
     * ȷ�����ұ߽��ʼ�������������ɵ���ˮ��
     * ֮�󽫵�ǰ�ұ߽���Ϊ�µ���߽�������㼴�ɡ�
     */
    int trap1(vector<int>& height) {
        int rain = 0;
        int left, right;
        left = 0;
        while (left < height.size()) {
            if (height[left] == 0) {
                left++;
            } else {
                // ȷ���˱߽��λ��,Ѱ���Ҳ�߽��λ�õ�λ��
                right = left + 1;
                if (right >= height.size()) {
                    break;
                }
                if (height[right] >= height[left]) {
                    left = right;
                    continue;
                }
                int max_height = height[right];
                int max_height_index = right;
                for (; right < height.size(); right++) {
                    if (max_height < height[right]) {
                        max_height = height[right];
                        max_height_index = right;
                    }
                    if (height[right] >= height[left]) {
                        break;
                    }
                }
                right = max_height_index;
                int rain_height = min(height[left], height[right]);
                for (int i = left + 1; i < right; i++) {
                    if (height[i] < rain_height) {
                        rain += rain_height - height[i];
                    }
                }
                left = right;
            }
        }
        return rain;
    }

    /**
     * ����2:����ջ��Ϊ����
     */
//    int trap2(vector<int>& height) {
//        stack<int> index_stack;
//        for (int i = 0; i < height.size(); i++) {
//            if (index_stack.size() == 0 || height)
//        }
//    }
};
