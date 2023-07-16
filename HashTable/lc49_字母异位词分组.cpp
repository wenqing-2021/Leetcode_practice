
/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
https://leetcode.cn/problems/group-anagrams/
*/

#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> mp;
        // main loop
        for (int i = 0; i < strs.size(); ++i){
            string str = strs[i];
            sort(str.begin(), str.end());
            if (mp.find(str) == mp.end()){
                vector<string> temp_str_vec;
                temp_str_vec.push_back(strs[i]);
                mp[str] = temp_str_vec;
            }
            else{
                auto it = mp.find(str);
                it->second.push_back(strs[i]);
            }
        }
        for (auto it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};