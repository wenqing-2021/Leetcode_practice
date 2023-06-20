
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int res;
        // dp[i] = dp[i-1] + (num[i] - num[i-1])
        // initial dp
        vector<int> dp(prices.size(), 0);
        if (prices[1] > prices[0]) dp[1] = prices[1] - prices[0];
        // initial res
        res = dp[1];
        for (int i = 2; i < prices.size(); ++i){
            dp[i] = dp[i-1] + (prices[i] - prices[i-1]);
            // avoid profit is less than zero
            if (dp[i] < 0) dp[i] = 0;
            if (dp[i] > res){
                res = dp[i];
            }
        }

        return res;

    }
};