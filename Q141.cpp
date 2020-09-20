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
     * 方法一:用一个Set盛放遇到过的链表节点,对链表进行遍历，如果遇到重复的就可以判断链表中有环
     * 时间复杂度O(n)，空间复杂度O(n)。（大概）
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
     * 设置快慢两个指针,快指针一次走两步、慢指针一次走一步。如果存在环，则快慢指针一定会相遇。
     * 如果存在环，设环的长度为k，因为对于快慢指针，每步两者间距减少1,因此时间复杂度为O(n + k)=O(n)
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