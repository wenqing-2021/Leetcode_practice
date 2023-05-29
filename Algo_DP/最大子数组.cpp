#include <vector>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        // dp[i] 表示：以 nums[i] 结尾的连续子数组的最大和
        vector<int> dp(len);
        int ret;
        dp[0] = nums[0];
        ret = dp[0];
        for (int i = 1; i < len; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > ret) ret = dp[i]; 
        }
        return ret;
    }
};