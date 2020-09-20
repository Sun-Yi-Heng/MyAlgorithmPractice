//
// Created by 孙一恒 on 2020/3/16.
//
#include "util.h"

void print_ListNode(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* makeList(vector<int> val_list) {
    ListNode* head = new ListNode(-1);
    ListNode* current = head;
    for (int i = 0; i < val_list.size(); i++) {
        ListNode* new_node = new ListNode(val_list[i]);
        current->next = new_node;
        current = current->next;
    }
    return head->next;
}

/**
 * 将source字符串按照separator划分,contain_empty设置了切分结果中是否包含空字符串
 */
vector<string> split(string source, string separator, bool contain_empty) {
    vector<string> result;
    int startPosition = 0;
    while (startPosition < source.size()) {
        int find_result = source.find(separator, startPosition);
        // 如果查找不到,就break
        if (find_result == string::npos) {
            break;
        }
        string part = source.substr(startPosition, find_result - startPosition);
        if (contain_empty || part != "") {
            result.push_back(part);
        }
        startPosition = find_result + separator.size();
    }
    if (result.size() == 0) {
        result.push_back(source);
    }
    return result;
}