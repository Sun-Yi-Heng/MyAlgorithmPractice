/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * ����һ:��һ��Setʢ��������������ڵ�,��������б�������������ظ��ľͿ����ж��������л�
     * ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)������ţ�
     */
    bool hasCycle(ListNode *head) {
        set<ListNode*> node_set;
        while (head != NULL) {
            if (node_set.find(head) != node_set.end()) {
                return true;
            }
            node_set.insert(head);
            head = head->next;
        }
        return false;
    }

    /**
     * ���ÿ�������ָ��,��ָ��һ������������ָ��һ����һ����������ڻ��������ָ��һ����������
     * ������ڻ����軷�ĳ���Ϊk����Ϊ���ڿ���ָ�룬ÿ�����߼�����1,���ʱ�临�Ӷ�ΪO(n + k)=O(n)
     */
    bool hasCycle1(ListNode *head) {
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        while (fast_ptr != NULL) {
            fast_ptr = fast_ptr->next;
            if (fast_ptr != NULL) {
                fast_ptr = fast_ptr->next;
            }
            slow_ptr = slow_ptr->next;
            if (slow_ptr == fast_ptr && slow_ptr != NULL) {
                return false;
            }
        }
        return true;
    }

};