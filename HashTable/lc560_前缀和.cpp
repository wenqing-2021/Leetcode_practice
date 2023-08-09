
/*

给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。

https://leetcode.cn/problems/subarray-sum-equals-k/solution/qian-zhui-he-ha-xi-fa-jie-huo-c-by-compa-3ipi/
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        for (auto& num_i : nums){
            presum += num_i;
            if (mp.find(presum-k) != mp.end()) ans += mp[presum-k];
            mp[presum]++;
        }
        
        return ans;
    }
};