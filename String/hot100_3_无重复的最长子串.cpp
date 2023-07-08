

/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
https://leetcode.cn/problems/longest-substring-without-repeating-characters/
*/


#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // two case
        // case_1 : dp[i] = dp[i-1] + 1
        // case_2 : dp[i] = dp[i-1] + (i-j) + 1
        int length = s.size();
        if (length <= 1) return length;
        vector<int> dp(length, 0);
        // initialization
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < length; ++i){
            pair<bool, int> repeat = isRepeat(s, i, dp);
            if (!repeat.first){
                dp[i] = dp[i-1] + 1;
            }
            else{
                int repeat_index = repeat.second;
                dp[i] = i - repeat_index;
            }
            if (dp[i] > res){
                res = dp[i];
            }
        }

        return res;
    }
    pair<bool, int> isRepeat(const string &s, int index, const vector<int> &dp){
        int l = dp[index-1];
        int start = index-l;
        int end = index;
        pair<bool, int> res;
        for (int j = start; j < end; ++j){
            if (s[j] == s[index]){
                res.first = true;
                res.second = j;
                return res;
            }
        }
        res.first = false;
        res.second = 0;
        return res;
    }
};


int main(){
    Solution s1;
    string s = "abcabcbb";
    int res = s1.lengthOfLongestSubstring(s);

    return 0;
}