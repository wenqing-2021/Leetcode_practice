
#include <vector>
using namespace std;

// 暴力搜索
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums[0] == 0 && nums.size() >= 1) {
            for (int i = 1; i < nums.size(); ++i){
                if (nums[i] - nums[i-1] > 1){
                    return int((nums[i] + nums[i-1]) / 2);
                }
            }
            return nums[nums.size()-1]+1;
        }
        
        return 0;
    }
};


// 二分法

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){
            int mid = i + (j-i) / 2;
            // 如果相等，往右边的子区间查找
            if (nums[mid] == mid) i = mid + 1;
            else j = mid - 1;
        }

        return i;
    }
};