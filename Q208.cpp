//
// Created by ��һ�� on 2020/3/23.
//

#include "util.h"

/**
 * ����һ:ʹ������hash_set�ֱ𱣴浱ǰ����ǰ׺�ļ��������������ַ����ļ���
 * �����������ҵ�ʱ�临�Ӷ�ΪO(1),�����ʱ�临�Ӷ�ΪO(n),nΪ�����ַ����ĳ���
 * ���Ǵ˷����Ŀռ临�ӶȽϸ�!
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
 * ������:
 * ����ʹ������״̬�Զ��������������
 * �÷��������ֲ�����ʱ�临�ӶȾ�ΪO(n),nΪ�����ַ����ĳ���
 * �÷�������Ч�������˿ռ䣬��Ӧ�ռ临�ӶȽϵͣ�ͬʱʵ�ʵ�ʱ�临�Ӷ�Ҳ�Ե��ڷ���1
 * ���е�ʵ�ַ��������ǵ������������ȷ���˳��ֵ��ַ�ֻ��26��,��һ������Ϊ26�����鱣������ת��!
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


