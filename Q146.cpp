//
// Created by 孙一恒 on 2020/3/14.
// Q146、LRU缓存机制
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
using namespace std;

class LRUCache {
public:
    /**
     * 最笨逼实现,用二个数组容量为n的数组分别存储key-value和最近使用时间,该方法的put和get的时间复杂度都为O(n),n为当前容量
     */
     int capacity;
    int current_capacity = 0;
    struct Pair{
        int key;
        int value;
        Pair(int key, int value): key(key), value(value){}
        Pair(){}
    };
    Pair* pair_array;
    int* last_used;
    int time = 0;

    LRUCache(int capacity) {
        // 这种在函数中申请的局部变量数组是否会因为方法返回栈空间被释放而导致错误？
        pair_array = new Pair[capacity];
        last_used = new int[capacity];
        this->capacity = capacity;
    }

    int get(int key) {
        for (int i = 0; i < current_capacity; i++) {
            if ((pair_array + i)->key == key) {
                *(last_used + i) = time--;
                return (pair_array + i)->value;
            }
        }
        return -1;
    }

    void put(int key, int value) {
        for (int i = 0; i < current_capacity; i++) {
            if ((pair_array + i)->key == key) {
                *(last_used + i) = time--;
                (pair_array + i)->value = value;
                return;
            }
        }
        if (current_capacity == capacity) {
            int max = *(last_used);
            int max_index = 0;
            for (int i = 1; i < capacity; i++) {
                if (*(last_used + i) > max) {
                    max = *(last_used + i);
                    max_index = i;
                }
            }
            (pair_array + max_index)->key = key;
            (pair_array + max_index)->value = value;
            *(last_used + max_index) = time--;
        } else {
            (pair_array + current_capacity)->key = key;
            (pair_array + current_capacity)->value = value;
            *(last_used + current_capacity) = time--;
            current_capacity++;
        }
    }
};

class LRUCache1 {
public:
    /**
     * 用双链表的节点配合map来存储键值对,
     * 同时,双向链表的头部的节点是最后一次使用的节点，即每当有节点被使用时，将其移动到链表头部,
     * 这样，相应的链表尾部的节点节点就是最近最少使用的节点。
     */
    struct ListNode{
        ListNode* prior;
        ListNode* next;
        int key;
        int value;
        ListNode(){}
    };

    int capacity;
    int current_capacity = 0;
    unordered_map<int, ListNode*> key_node_map;
    // 定义我们双向链表的头和尾
    ListNode* head = new ListNode();
    ListNode* tail = new ListNode();

    LRUCache1(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prior = head;
    }

    int get(int key) {
        auto result = key_node_map.find(key);
        if (result != key_node_map.end()) {
            move_to_head(result->second);
            return result->second->value;
        }
        return -1;
    }

    void move_to_head(ListNode* node) {
        ListNode* node_next = node->next;
        ListNode* node_prior = node->prior;
        node_prior->next = node_next;
        node_next->prior = node_prior;
        ListNode* head_next = head->next;
        head->next = node;
        node->prior = head;
        node->next = head_next;
        head_next->prior = node;
    }

    void put(int key, int value) {
        // 若key本身就处于容器中,只需要更新其value值并将其设置为最近使用。
        auto result = key_node_map.find(key);
        if (result != key_node_map.end()) {
            result->second->value = value;
            move_to_head(result->second);
            return;
        }
        // 否则根据容器是否已满决定处理策略
        ListNode* node = new ListNode();
        node->value = value;
        node->key = key;
        key_node_map[key] = node;
        if (current_capacity != capacity) {
            // 将节点插到头部的后一个节点中
            ListNode* head_next = head->next;
            head->next = node;
            node->prior = head;
            node->next = head_next;
            head_next->prior = node;
            current_capacity++;
        } else {
            // 容器已满,则先删除最近最少使用的节点，即tail的前一个节点。
            key_node_map.erase(tail->prior->key);

            tail->prior->prior->next = tail;
            tail->prior = tail->prior->prior;
            // 将节点插到头部的后一个节点中
            ListNode* head_next = head->next;
            head->next = node;
            node->prior = head;
            node->next = head_next;
            head_next->prior = node;
        }
    }
};


