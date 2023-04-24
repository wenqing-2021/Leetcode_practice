#include <vector>
using namespace std;


class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3){
            return n - 1;
        }
        vector<int> dp(n+1);
        dp[2] = 1;
        dp[1] = 1;
        for (int i = 3; i < n+1; ++i){
            for (int j = 1; j < i; ++j){
                dp[i] = max(dp[i], max(dp[j] * (i - j), j*(i-j)));
            }
        }
        return dp[n];
    }
};