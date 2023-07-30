/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        for (auto c: t) ht[c] ++ ;
        string res;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            hs[s[i]] ++ ;
            if (hs[s[i]] <= ht[s[i]]) cnt ++ ;

            while (hs[s[j]] > ht[s[j]]) hs[s[j ++ ]] -- ;
            if (cnt == t.size()) {
                if (res.empty() || i - j + 1 < res.size())
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};