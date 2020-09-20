//
// Created by ��һ�� on 2020/3/14.
// Q146��LRU�������
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
using namespace std;

class LRUCache {
public:
    /**
     * ���ʵ��,�ö�����������Ϊn������ֱ�洢key-value�����ʹ��ʱ��,�÷�����put��get��ʱ�临�Ӷȶ�ΪO(n),nΪ��ǰ����
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
        // �����ں���������ľֲ����������Ƿ����Ϊ��������ջ�ռ䱻�ͷŶ����´���
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
     * ��˫����Ľڵ����map���洢��ֵ��,
     * ͬʱ,˫�������ͷ���Ľڵ������һ��ʹ�õĽڵ㣬��ÿ���нڵ㱻ʹ��ʱ�������ƶ�������ͷ��,
     * ��������Ӧ������β���Ľڵ�ڵ�����������ʹ�õĽڵ㡣
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
    // ��������˫�������ͷ��β
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
        // ��key����ʹ���������,ֻ��Ҫ������valueֵ����������Ϊ���ʹ�á�
        auto result = key_node_map.find(key);
        if (result != key_node_map.end()) {
            result->second->value = value;
            move_to_head(result->second);
            return;
        }
        // ������������Ƿ����������������
        ListNode* node = new ListNode();
        node->value = value;
        node->key = key;
        key_node_map[key] = node;
        if (current_capacity != capacity) {
            // ���ڵ�嵽ͷ���ĺ�һ���ڵ���
            ListNode* head_next = head->next;
            head->next = node;
            node->prior = head;
            node->next = head_next;
            head_next->prior = node;
            current_capacity++;
        } else {
            // ��������,����ɾ���������ʹ�õĽڵ㣬��tail��ǰһ���ڵ㡣
            key_node_map.erase(tail->prior->key);

            tail->prior->prior->next = tail;
            tail->prior = tail->prior->prior;
            // ���ڵ�嵽ͷ���ĺ�һ���ڵ���
            ListNode* head_next = head->next;
            head->next = node;
            node->prior = head;
            node->next = head_next;
            head_next->prior = node;
        }
    }
};


