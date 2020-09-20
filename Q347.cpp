//
// Created by 孙一恒 on 2020/5/2.
// Q347、前k个高频元素
//
#include "util.h"

class Solution {
public:
    /**
     * 用hash_map对nums遍历，计算各元素的出现次数,然后插入vector中利用自定义的比较函数排序
     * 时间复杂度O(nlgn)
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
     * 调整以K为根的heap,使其仍满足一个堆
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
     * 方法2:同样先用hash_map统计各元素出现次数,然后维护一个大小为k的最小堆
     * 然后把元素插入最小堆中,最后全部插入完毕后,堆中剩下的元素就是我们所求
     * (原因在于最小堆的堆顶是当前堆中的最小元素,如果来了一个频率更高的元素,最小堆的堆顶就会被弹出)
     * 由于插入大小为k的堆的时间复杂度为O(lgk),因此该方法的时间复杂度为O(nlgk),优于方法1
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
     * 方法3:由于根据题目中的提示,前k个高频元素的结果是唯一的,对于用hash_map统计后的结果,我们创建一个大小为nums.size + 1的数组,
     * 然后将hash_map中的key:value，进行复制 n[value] = key,对数组从后向前遍历,选出前k个赋值即可
     * 该方法的时间复杂度为O(n),空间复杂度为O(n)
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

