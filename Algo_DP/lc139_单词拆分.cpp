/*

给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

*/
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i){
            for (const auto& s_i : wordDict){
                int cur_len = s_i.size();
                if (i - cur_len >= 0 && s.substr(i - cur_len, cur_len) == s_i){
                    dp[i] = dp[i] || dp[i-cur_len];
                }
            }
        }

        return dp[n];
    }
};