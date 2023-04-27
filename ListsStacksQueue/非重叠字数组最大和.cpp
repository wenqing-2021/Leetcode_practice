

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int help(vector<int>& nums, int firstLen, int secondLen) {
        // 初始化，计算sum left和sum right的初始值
        int suml = accumulate(nums.begin(), nums.begin() + firstLen, 0);
        int maxSumL = suml;
        int sumr = accumulate(nums.begin() + firstLen, nums.begin() + firstLen + secondLen, 0);
        int res = maxSumL + sumr;
        for (int i = firstLen + secondLen, j = firstLen; i < nums.size(); ++i, ++j) {
            // 计算多加了一个元素后的值
            suml += nums[j] - nums[j - firstLen];
            // 找到最大值
            maxSumL = max(maxSumL, suml);
            sumr += nums[i] - nums[i - secondLen];
            res = max(res, maxSumL + sumr);
        }
        return res;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(help(nums, firstLen, secondLen), help(nums, secondLen, firstLen));
    }
};