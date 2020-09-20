//
// Created by ��һ�� on 2020/2/10.
// Q49����ĸ��λ�ʷ���
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * ����1:��������ַ�����ÿ���ַ����е��ַ�����ascii�ַ�����,Ȼ��������μ�����Ƿ�����Ӧ�ķ��飬�оͲ��뵽��Ӧ����,û�оʹ����µġ�
     * ��������ַ�������Ϊn��ÿ���ַ����ĳ��ȶ�Ϊk����ʱ�临�Ӷ�ΪO(n * k * lgk), �ռ临�Ӷ�ΪO(n * k)
     */
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        vector<vector<string>> result;
//        map<string, vector<string>> class_map;
//        string* after_sort;
//        for (string s : strs) {
//            after_sort = new string(s);
//            sort(after_sort->begin(), after_sort->end());
//            auto find_result = class_map.find(*after_sort);
//            if (find_result == class_map.end()) {
//                vector<string> new_vector;
//                new_vector.push_back(s);
//                class_map[*after_sort] = new_vector;
//            } else {
//                find_result->second.push_back(s);
//            }
//        }
//        for (auto pair : class_map) {
//            result.push_back(pair.second);
//        }
//        return result;
//    }
    // ���ܽϺõ�ʵ��
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> M;
        for(int i=0;i<strs.size();i++){
            string key=strs[i];
            sort(key.begin(),key.end());
            M[key].push_back(strs[i]);
        }
        for(auto ite=M.begin();ite!=M.end();ite++)
            res.push_back(ite->second);
        return res;
    }

    /**
     * �������һ���������ǳ����ʱ�临�Ӷ�,���Ǳ����ַ����е������ַ������������¼�¸����ַ�������,Ȼ�������ƴ�ӳ�һ�����ַ���,
     * ��Ϊmap��key������������ʡȥ��ƽ��ʱ�临�Ӷ�ΪO(k * lgk)���ַ�������,ʱ�临�Ӷȱ�ΪO(n * k)
     */
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> class_map;
        int chars_num[26];
        string* after_sort;
        for (string s : strs) {
            after_sort = new string();
            // ����������ʼ��Ϊ0
            for (int i = 0; i < 26; i++) {
                chars_num[i] = 0;
            }
            for (char c : s) {
                chars_num[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < chars_num[i]; j++) {
                    *after_sort = *after_sort + (char)(i + 'a');
                }
            }
            auto find_result = class_map.find(*after_sort);
            if (find_result == class_map.end()) {
                vector<string> new_vector;
                new_vector.push_back(s);
                class_map[*after_sort] = new_vector;
            } else {
                find_result->second.push_back(s);
            }
        }
        for (auto pair : class_map) {
            result.push_back(pair.second);
        }
        return result;
    }
};

//int main() {
//    Solution *s = new Solution();
//    vector<string> v({"eat","tea","tan","ate","nat","bat"});
//    s->groupAnagrams(v);
//}

