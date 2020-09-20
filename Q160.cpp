//
// Created by 孙一恒 on 2020/3/19.
// Q160、相交链表
//

#include "util.h"

class Solution {
public:
    /*
     * 方法1:使用两个指针分别遍历链表,使用hash_set结构存储已经遍历过的节点,如果两个链表相交,则在hash_set中必能找到已有节点
     * 时间复杂度O(n)（n为总结点数）,空间复杂度O(n)
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> node_set;
        ListNode *currentA = headA;
        ListNode *currentB = headB;
        while (currentA != NULL || currentB != NULL) {
            if (currentA != NULL) {
                if (node_set.find(currentA) != node_set.end()) {
                    return currentA;
                }
                node_set.insert(currentA);
                currentA = currentA->next;
            }
            if (currentB != NULL) {
                if (node_set.find(currentB) != node_set.end()) {
                    return currentB;
                }
                node_set.insert(currentB);
                currentB = currentB->next;
            }
        }
        return NULL;
    }

    /**
     * 由于题目要求时间复杂度为O(n),空间复杂度为O(1),
     * 我们修改上面的方法,改为两轮遍历,如果两个链表相交,则其最后一个节点一定相等
     * 因此我们第一轮遍历用来判断两个链表是否相交以及各自的长度
     * 如果相交，我们根据长度只差就可得知他们的交点了。
     */
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> node_set;
        ListNode *currentA = headA;
        ListNode *currentB = headB;
        if (currentA == NULL || currentB == NULL) {
            return NULL;
        }
        int lengthA = 1, lengthB = 1;
        while (currentA->next != NULL){
            currentA = currentA->next;
            lengthA++;
        }
        while (currentB->next != NULL) {
            currentB = currentB->next;
            lengthB++;
        }
        // 当前currentA和currentB指向最后一个节点
        if (currentA == currentB) {
            int gap = lengthA - lengthB;
            currentA = headA;
            currentB = headB;
            if (gap > 0) {
                for (int i = 0; i < gap; i++) {
                    currentA = currentA->next;
                }
            } else if (gap < 0) {
                for (int i = 0; i < -gap; i++) {
                    currentB = currentB->next;
                }
            }
            while (true) {
                if (currentA == currentB) {
                    return currentA;
                }
                currentA = currentA->next;
                currentB = currentB->next;
            }

        }
        return NULL;
    }
};

