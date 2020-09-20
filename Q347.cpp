//
// Created by ��һ�� on 2020/5/2.
// Q347��ǰk����ƵԪ��
//
#include "util.h"

class Solution {
public:
    /**
     * ��hash_map��nums�����������Ԫ�صĳ��ִ���,Ȼ�����vector�������Զ���ıȽϺ�������
     * ʱ�临�Ӷ�O(nlgn)
     */
    struct Pair {
        int key;
        int times;
        Pair(int key, int times):key(key), times(times){}
    };

    static bool myCompare(Pair p1, Pair p2) {
        return p1.times > p2.times;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> appears_times;
        vector<int> result;
        vector<Pair> pairVector;
        for (int i = 0; i < nums.size(); i++) {
            auto find_result = appears_times.find(nums[i]);
            if (find_result == appears_times.end()) {
                appears_times[nums[i]] = 1;
            } else {
                find_result->second++;
            }
        }
        for (auto i = appears_times.begin(); i != appears_times.end(); i++) {
            Pair p(i->first, i->second);
            pairVector.push_back(p);
        }
        sort(pairVector.begin(), pairVector.end(), myCompare);
        for (int i = 0; i < k; i++) {
            result.push_back(pairVector[i].key);
        }
        return result;
    }

    void insert_heap(Pair* heap[], int k, Pair* p) {
        static int i = 0;
        if (i < k) {
            heap[k - i - 1] = p;
            heapify(heap, k - i - 1, k);
            i++;
        } else if (heap[0]->times < p->times) {
            heap[0] = p;
            heapify(heap, 0, k);
        }
    }

    /**
     * ������KΪ����heap,ʹ��������һ����
     * @param heap
     * @param root
     */
    void heapify(Pair* heap[], int root, int k) {
        int current = root;
        Pair* temp = NULL;
        while (true) {
            if (2 * current + 1 < k) {
                if (heap[current] > heap[2 * current + 1]) {
                    temp = heap[current];
                    heap[current] = heap[2 * current + 1];
                    heap[2 * current + 1] = temp;
                    current = 2 * current + 1;
                    continue;
                }
            }
            if (2 * current + 2 < k) {
                if (heap[current] > heap[2 * current + 2]) {
                    temp = heap[current];
                    heap[current] = heap[2 * current + 2];
                    heap[2 * current + 2] = temp;
                    current = 2 * current + 2;
                    continue;
                }
            }
            break;
        }
    }

    /**
     * ����2:ͬ������hash_mapͳ�Ƹ�Ԫ�س��ִ���,Ȼ��ά��һ����СΪk����С��
     * Ȼ���Ԫ�ز�����С����,���ȫ��������Ϻ�,����ʣ�µ�Ԫ�ؾ�����������
     * (ԭ��������С�ѵĶѶ��ǵ�ǰ���е���СԪ��,�������һ��Ƶ�ʸ��ߵ�Ԫ��,��С�ѵĶѶ��ͻᱻ����)
     * ���ڲ����СΪk�Ķѵ�ʱ�临�Ӷ�ΪO(lgk),��˸÷�����ʱ�临�Ӷ�ΪO(nlgk),���ڷ���1
     */
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        unordered_map<int, int> appears_times;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            auto find_result = appears_times.find(nums[i]);
            if (find_result == appears_times.end()) {
                appears_times[nums[i]] = 1;
            } else {
                find_result->second++;
            }
        }

        Pair* heap[k];
        for (int i = 0; i < k; i++) {
            heap[i] = NULL;
        }
        for (auto i = appears_times.begin(); i != appears_times.end(); i++) {
            Pair* p = new Pair(i->first, i->second);
            insert_heap(heap, k, p);
        }
        for (int i = 0; i < k; i++) {
            result.push_back(heap[i]->key);
        }
        return result;
    }

    /**
     * ����3:���ڸ�����Ŀ�е���ʾ,ǰk����ƵԪ�صĽ����Ψһ��,������hash_mapͳ�ƺ�Ľ��,���Ǵ���һ����СΪnums.size + 1������,
     * Ȼ��hash_map�е�key:value�����и��� n[value] = key,������Ӻ���ǰ����,ѡ��ǰk����ֵ����
     * �÷�����ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(n)
     */
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        unordered_map<int, int> appears_times;
        vector<int> result;
        vector<int> n[nums.size() + 1];
        for (int i = 0; i < nums.size(); i++) {
            auto find_result = appears_times.find(nums[i]);
            if (find_result == appears_times.end()) {
                appears_times[nums[i]] = 1;
            } else {
                find_result->second++;
            }
        }
        for (auto i = appears_times.begin(); i != appears_times.end(); i++) {
            n[i->second].push_back(i->first);
        }
        for (int i = nums.size(); i >= 0 && k > 0; i--) {
            for (int j = 0; j < n[i].size(); j++) {
                result.push_back(n[i][j]);
                k--;
            }
        }
        return result;
    }
};

