/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 小到大排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        // 如果第一个元素大于0直接退出
        if (nums[0] > 0) return res;

        // 遍历排序后的数组 (三指针循环，固定一个，循环其他两个)
        for (int i = 0; i < nums.size(); ++i){
            // if the same element continue
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0){
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    res.push_back(temp);
                    // move the left or right
                    // if the same element, pass it
                    while (left < right && nums[left] == nums[left+1]){
                        left++;
                    }
                    while (left < right && nums[right] == nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                // move the left to bigger num
                else if (sum < 0){
                    left++;
                }
                // move the right to smaller num
                else{
                    right--;
                }
            }
        }

        return res;

    }
};