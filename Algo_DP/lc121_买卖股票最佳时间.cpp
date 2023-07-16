
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n); // 第i天卖出的最大收益
        dp[0] = 0;
        int profit = 0;
        for (int i = 1; i < n; ++i){
            int diff = prices[i] - prices[i-1];
            dp[i] = max(dp[i-1] + diff, 0);
            if (dp[i] > profit) profit = dp[i];
        }

        return profit;
    }
};