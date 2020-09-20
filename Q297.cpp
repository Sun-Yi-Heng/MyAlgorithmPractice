//
// Created by 孙一恒 on 2020/4/3.
// Q297、二叉树的序列化与反序列化
//
#include "util.h"

/**
 * 思路1:我们将二叉树序列化成按层序遍历得到的结果,用逗号分隔
 * 如1,2,null
 * 序列化的时间复杂度O(n),n为二叉树节点个数
 * 反序列化的时间复杂度为O(n),n为节点个数
 * 提交后超时
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "null";
        }
        string str = "";
        queue<TreeNode*> current_layer;
        current_layer.push(root);
        bool flag = true;
        while (flag) {
            queue<TreeNode*> next_layer;
            flag = false;
            while (current_layer.size() != 0) {
                TreeNode *front = current_layer.front();
                current_layer.pop();
                // 如果当前节点为空,其左右子树也为空
                if (front == NULL) {
                    next_layer.push(NULL);
                    next_layer.push(NULL);
                    str += "null,";
                } else {
                    flag = true;
                    next_layer.push(front->left);
                    next_layer.push(front->right);
                    str = str + to_string(front->val) + ",";
                }
            }
            current_layer = next_layer;
        }
        return str.substr(0, str.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") {
            return NULL;
        }
        vector<string> after_split;
        // 切割字符串
        vector<string> result = split(data, ",", false);
        vector<TreeNode*> tree_vector;
        TreeNode *root = new TreeNode(stoi(result[0]));
        tree_vector.push_back(root);
        for (int i = 1; i < result.size(); i++) {
            if (result[i] == "null") {
                tree_vector.push_back(NULL);
                continue;
            } else {
                TreeNode *new_node = new TreeNode(stoi(result[i]));
                tree_vector.push_back(new_node);
                TreeNode* parent = tree_vector[(i - 1) / 2];
                if (i % 2 == 0) {
                    parent->right = new_node;
                } else {
                    parent->left = new_node;
                }
            }
        }
        return root;
    }

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
        string last = source.substr(startPosition);
        if (contain_empty || last != "") {
            result.push_back(last);
        }
        return result;
    }
};

/**
 * 思路2:采用DFS(前序、中序、后序遍历均可）
 * 一开始考虑时觉得至少结合两种遍历得到的序列才能还原二叉树，但如果我们遍历时保存null节点,只需一种遍历即可还原
 * 不知道为什么也超时了...
 */
class Codec1 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        if (root == NULL) {
            return "null";
        }
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (node_stack.size() != 0) {
            TreeNode *current = node_stack.top();
            node_stack.pop();
            if (current == NULL) {
                result += "null,";
            } else {
                result = result + to_string(current->val) + ",";
                node_stack.push(current->right);
                node_stack.push(current->left);
            }
        }
        return result.substr(0, result.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> node_vector = split(data, ",", false);
        return recursive_deserialize(node_vector);
    }

    TreeNode *recursive_deserialize(vector<string>& current_vector) {
        if (current_vector.size() == 0) {
            return NULL;
        }
        string current = current_vector[0];
        current_vector.erase(current_vector.begin());
        if (current == "null") {
            return NULL;
        }
        TreeNode *new_node = new TreeNode(stoi(current));
        new_node->left = recursive_deserialize(current_vector);
        new_node->right = recursive_deserialize(current_vector);
        return new_node;
    }
};
