
/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
*/
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        map<char, int> dict_map;
        dict_map['('] = n;
        dict_map[')'] = n;
        vector<string> res;
        string temp;
        backtracking(res, dict_map, temp);

        return res;
    }

    void backtracking(vector<string>& res, map<char, int>& dict_map, string& temp){
        // terminal condition
        if (dict_map.find(')')->second == 0){
            res.push_back(temp);
            return;
        }
        vector<char> selection_vec = {'(', ')'};
        for (auto& char_i : selection_vec){
            auto it = dict_map.find(char_i);
            if (char_i == '(' && it->second == 0) continue;
            if (char_i == ')'){
                auto it_pre = dict_map.find('(');
                if (it_pre->second > it->second-1){
                    return;
                }
            }
            it->second = it->second - 1;
            temp.push_back(char_i);
            backtracking(res, dict_map, temp);
            temp.pop_back();
            it->second = it->second + 1;
        }
    }
};



