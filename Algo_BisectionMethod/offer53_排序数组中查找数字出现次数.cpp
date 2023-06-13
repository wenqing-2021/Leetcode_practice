
#include <vector>
using namespace std;

class Solution {
public:
    //二分查找右边界 right
    int helper(vector<int>& nums, int tar){
        int i = 0, j = nums.size() - 1;
        while(i <= j) {
            int m = (i + j) / 2;
            if(nums[m] <= tar) i = m + 1;   //左边界nums[m] < target
            else j = m - 1;
        }
        return i;
    }
    int search(vector<int>& nums, int target) {
        //target的右边界 - (target-1)的右边界
        return helper(nums, target) - helper(nums, target - 1);
    }
};