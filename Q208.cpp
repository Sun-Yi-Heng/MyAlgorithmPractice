//
// Created by 孙一恒 on 2020/3/23.
//

#include "util.h"

/**
 * 方法一:使用两个hash_set分别保存当前所有前缀的集合与所有树中字符串的集合
 * 这样两个查找的时间复杂度为O(1),插入的时间复杂度为O(n),n为插入字符串的长度
 * 但是此方法的空间复杂度较高!
 */
class Trie {
public:
    unordered_set<string> prefix_set;
    unordered_set<string> string_set;
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        string_set.insert(word);
        for (int i = 0; i < word.size(); i++) {
            prefix_set.insert(word.substr(0, i + 1));
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return string_set.find(word) != string_set.end();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefix_set.find(prefix) != prefix_set.end();
    }
};

/**
 * 方法二:
 * 我们使用有穷状态自动机来解决此问题
 * 该方法的三种操作的时间复杂度均为O(n),n为传入字符串的长度
 * 该方法较有效的利用了空间，对应空间复杂度较低，同时实际的时间复杂度也略低于方法1
 * 答案中的实现方法与我们的区别就在于其确定了出现的字符只有26个,用一个长度为26的数组保存了跳转表!
 */
class Trie1 {
public:
    struct StateNode {
        unordered_map<char, StateNode*> jump_table;
        bool end;
        StateNode(bool end): end(end){}
        StateNode():end(false){}
    };

    StateNode *head_node = new StateNode(true);
    /** Initialize your data structure here. */
    Trie1() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        StateNode* current_state = head_node;
        for (int i = 0; i < word.size(); i++) {
            auto find_result = current_state->jump_table.find(word[i]);
            if (find_result == current_state->jump_table.end()) {
                StateNode* new_state = new StateNode();
                current_state->jump_table[word[i]] = new_state;
                current_state = new_state;
            } else {
                current_state = current_state->jump_table[word[i]];
            }
        }
        current_state->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        StateNode* current_state = head_node;
        for (int i = 0; i < word.size(); i++) {
            auto find_result = current_state->jump_table.find(word[i]);
            if (find_result == current_state->jump_table.end()) {
                return false;
            } else {
                current_state = current_state->jump_table[word[i]];
            }
        }
        return current_state->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        StateNode* current_state = head_node;
        for (int i = 0; i < prefix.size(); i++) {
            auto find_result = current_state->jump_table.find(prefix[i]);
            if (find_result == current_state->jump_table.end()) {
                return false;
            } else {
                current_state = current_state->jump_table[prefix[i]];
            }
        }
        return true;
    }
};


