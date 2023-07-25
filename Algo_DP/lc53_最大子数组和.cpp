/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

https://leetcode.cn/problems/maximum-subarray/
*/

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // 最大子数组和dp, dp[i] presens the maxium sum at the end of i
        // dp[i] = dp[i-1] + nums[i] if nums[i] > 0
        // 如果
        vector<int> dp(n);
        dp[0] = nums[0];
        int max_num = dp[0];
        for (int i = 1; i < nums.size(); ++i){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            if (dp[i] > max_num){
                max_num = dp[i];
            }
        }

        return max_num;
        
    }
};