
#include <vector>
using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        // initial
        vector<double> dp(6, 1.0 / 6.0);

        // transition
        for (int k = 2; k <= n; ++k){
            vector<double> pos_sum(5*k+1, 0);
            for (int j = 0; j < dp.size(); ++j){
                for (int i = 0; i < 6; ++i){
                    // 正向构造，f(n-1, x)只影响 f(n, x+1), ..., f(n, x+6)
                    pos_sum[j + i] += dp[j] / 6.0;
                }
            }
            // update the latest dp
            dp = pos_sum;
        }


        return dp;
    }
};