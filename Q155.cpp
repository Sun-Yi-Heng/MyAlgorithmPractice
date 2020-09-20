//
// Created by 孙一恒 on 2020/3/18.
// Q155、最小栈
//
#include "util.h"

/**
 * 最小栈实现方法1:底层采用链表存储,获取最小元素时,通过遍历链表完成。
 * 这样getMin()的时间复杂度为O(n),而其余操作的时间复杂度均为O(1)
 */
class MinStack {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* head = new ListNode(-1);

    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        ListNode *current = new ListNode(x);
        current->next = head->next;
        head->next = current;
    }

    void pop() {
        head->next = head->next->next;
    }

    int top() {
        return head->next->val;
    }

    int getMin() {
        int minVal = head->next->val;
        ListNode *current = head->next;
        while (current != NULL) {
            minVal = min(minVal, current->val);
            current = current->next;
        }
        return minVal;
    }
};


/**
 * 最小栈实现方法2:底层采用链表存储,为了能够在O(1)的时间内获得最小元素
 * 我们维护两个链表，一个就是按栈的结构进行组织的，另一个则是按照元素由小到大排列的,
 * 这样,push和pop的时间复杂度变为O(n),而getMin()的时间复杂度为O(1)
 */
class MinStack1 {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* stack_head = new ListNode(-1);
    ListNode *ordered_head = new ListNode(-1);

    /** initialize your data structure here. */
    MinStack1() {

    }

    void push(int x) {
        ListNode *new_stack_node = new ListNode(x);
        ListNode *new_ordered_node = new ListNode(x);
        new_stack_node->next = stack_head->next;
        stack_head->next = new_stack_node;
        ListNode* previous = ordered_head;
        ListNode *current = ordered_head->next;
        while (current!= NULL && x > current->val) {
            previous = current;
            current = current->next;
        }
        new_ordered_node->next = previous->next;
        previous->next = new_ordered_node;
    }

    void pop() {
        int value = stack_head->next->val;
        stack_head->next = stack_head->next->next;
        ListNode *current = ordered_head->next;
        ListNode *previous = ordered_head;
        while (true) {
            if (current->val == value) {
                previous->next = previous->next->next;
                break;
            }
            previous = current;
            current = current->next;
        }
    }

    int top() {
        return stack_head->next->val;
    }

    int getMin() {
        return ordered_head->next->val;
    }
};


/**
 * 最小栈实现方法3:底层采用链表存储,为了能够在O(1)的时间内获得最小元素
 * 我们维护两个链表，一个就是按栈的结构进行组织的，另一个链表只要记录栈各个状态下当前最小元素即可,不用像方法2中那样进行排序
 * 这样所有操作的时间复杂度为O(1),空间复杂度为O(n)
 */
class MinStack2 {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* stack_head = new ListNode(-1);
    ListNode *helper_head = new ListNode(-1);

    /** initialize your data structure here. */
    MinStack2() {

    }

    void push(int x) {
        ListNode *new_stack_node = new ListNode(x);
        new_stack_node->next = stack_head->next;
        stack_head->next = new_stack_node;

        if (helper_head->next == NULL || x < helper_head->next->val) {
            ListNode *helper_node = new ListNode(x);
            helper_node->next = helper_head->next;
            helper_head->next = helper_node;
        } else {
            ListNode *helper_node = new ListNode(helper_head->next->val);
            helper_node->next = helper_head->next;
            helper_head->next = helper_node;
        }
    }

    void pop() {
        stack_head->next = stack_head->next->next;
        helper_head->next = helper_head->next->next;
    }

    int top() {
        return stack_head->next->val;
    }

    int getMin() {
        return helper_head->next->val;
    }
};
