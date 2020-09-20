//
// Created by ��һ�� on 2020/3/19.
// Q160���ཻ����
//

#include "util.h"

class Solution {
public:
    /*
     * ����1:ʹ������ָ��ֱ��������,ʹ��hash_set�ṹ�洢�Ѿ��������Ľڵ�,������������ཻ,����hash_set�б����ҵ����нڵ�
     * ʱ�临�Ӷ�O(n)��nΪ�ܽ������,�ռ临�Ӷ�O(n)
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
     * ������ĿҪ��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1),
     * �����޸�����ķ���,��Ϊ���ֱ���,������������ཻ,�������һ���ڵ�һ�����
     * ������ǵ�һ�ֱ��������ж����������Ƿ��ཻ�Լ����Եĳ���
     * ����ཻ�����Ǹ��ݳ���ֻ��Ϳɵ�֪���ǵĽ����ˡ�
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
        // ��ǰcurrentA��currentBָ�����һ���ڵ�
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

