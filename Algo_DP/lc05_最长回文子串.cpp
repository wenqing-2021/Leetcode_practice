
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][j]代表区间[i, j]是否含有回文子串
        // 如果s[i] = s[j]，且 dp[i+1][j-1] = true，则dp[i][j]也为true。
        int size = s.size();
        if (size == 1) return s;
        string res;
        int maxLength = 0;
        // 防止dp[i+1][j-1]越界
        vector<vector<bool>> dp(size+1, vector<bool>(size+1, false));

        for (int i = size - 1; i >= 0; --i){
            for (int j = i; j < size; ++j){
                if ((j-i) == 0){
                    dp[i][j] = true;
                }
                else if ((j-i) == 1 && (s[i] == s[j])){
                    dp[i][j] = true;
                }
                else{
                    if (dp[i+1][j-1] && s[i] == s[j]){
                        dp[i][j] = true;
                    }
                }
                if ((j - i) >= maxLength && dp[i][j]){
                    maxLength = j- i + 1;
                    res = s.substr(i, maxLength);
                }
            }
        }

        return res;
    }
};