//
// Created by 孙一恒 on 2020/2/10.
// Q49、字母异位词分组
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * 方法1:将传入的字符串中每个字符串中的字符按照ascii字符排序,然后根据依次检查其是否有相应的分组，有就插入到相应分组,没有就创建新的。
     * 若传入的字符串数量为n，每个字符串的长度都为k，则时间复杂度为O(n * k * lgk), 空间复杂度为O(n * k)
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
    // 性能较好的实现
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
     * 我们想进一步降低我们程序的时间复杂度,我们遍历字符串中的所有字符，并用数组记录下各个字符的数量,然后根据其拼接出一个新字符串,
     * 作为map的key，这样，我们省去了平均时间复杂度为O(k * lgk)的字符串排序,时间复杂度变为O(n * k)
     */
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> class_map;
        int chars_num[26];
        string* after_sort;
        for (string s : strs) {
            after_sort = new string();
            // 将计数器初始化为0
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

