#include <string>
#include <vector>
using namespace std;

/*
假设dp[i][j]表示s的前i个字符和p的前j个字符是否匹配，其中s和p的下标从0开始。
那么可以分为以下几种情况：

如果p[j-1]是普通字符，那么只有当s[i-1]和p[j-1]相同，且s的前i-1个字符和p的前j-1个字符是匹配的，才有dp[i][j]=True。

如果p[j-1]是'.'，那么可以匹配任意字符，因此只有当s的前i-1个字符和p的前j-1个字符是匹配的，才有dp[i][j]=True。

如果p[j-1]是'*'，那么可以匹配零个或多个前面的那一个元素。因此需要考虑以下两种情况：

(1) 匹配零个前面的元素。此时dp[i][j]=dp[i][j-2]，表示s的前i个字符和p的前j-2个字符是匹配的。

(2) 匹配多个前面的元素。此时需要满足以下两个条件：


a. s[i-1]和p[j-2]相同或者p[j-2]是'.'，表示前面的元素可以匹配s[i-1]。

b. s的前i-1个字符和p的前j个字符是匹配的，即dp[i-1][j]=True。

作者：absent
链接：https://leetcode.cn/problems/regular-expression-matching/solution/10-zheng-ze-biao-da-shi-pi-pei-chatgptde-ojmc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1));
        dp[0][0] = true;

        // 初始化第一行，考虑*情况
        for (int j = 2; j <= n; j++) {
            dp[0][j] = dp[0][j-2] && p[j-1] == '*';
        }

        // 状态转移
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] != '*') {
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                } else {
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }
            }
        }

        return dp[m][n];
    }
};