
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int max_num;
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        map<char, string> phone_dict;
        phone_dict['2'] = "abc";
        phone_dict['3'] = "def";
        phone_dict['4'] = "ghi";
        phone_dict['5'] = "jkl";
        phone_dict['6'] = "mno";
        phone_dict['7'] = "pqrs";
        phone_dict['8'] = "tuv";
        phone_dict['9'] = "wxyz";
        vector<string> all_string;
        for (auto& num : digits){
            auto iter = phone_dict.find(num);
            all_string.push_back(iter->second);
        }
        max_num = digits.size();
        string temp_res;
        backtracking(res, all_string, 0, temp_res);

        return res;
    }
    void backtracking(vector<string> &res, const vector<string> &all_string, int i, string &temp_res){
        // 终止条件
        if (i == max_num - 1){
            for (auto &char_num : all_string[i]){
                // 依次插入最后一个数字对应string中的char
                temp_res.push_back(char_num);
                res.push_back(temp_res);
                // 需要将最后一个char弹出
                temp_res.pop_back();
            }
            return;
        }
        // 循环当前所在数字位i的string
        for (int j = 0; j < all_string[i].size(); ++j){
            temp_res.push_back(all_string[i][j]);
            // 进行下一个数字的递归
            backtracking(res, all_string, i+1, temp_res);
            // 弹出刚刚插入的char
            temp_res.pop_back();
        }

        return;
    }
};