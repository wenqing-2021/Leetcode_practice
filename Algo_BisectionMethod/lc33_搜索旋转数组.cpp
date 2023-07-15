/*
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1){
            if (nums[0] == target) return 0;
            return -1;
        }
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right && nums[left] > nums[right]){
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]){
                left = mid + 1;
            }
            else if (nums[mid] == target){
                return mid;
            }
            else{
                right = mid - 1;
            }
        }
        if (left == 0 && right == 0) left = 1;
        if ((left+1) < nums.size() && nums[left] > nums[left+1]) left++;
        if (left == 0 && right != 0 && right+1 < nums.size()) left = right+1;
        vector<int> pre_nums(nums.begin(), nums.begin() + left);
        vector<int> post_nums(nums.begin() + left, nums.end());
        int find_pre = -1;
        if (!pre_nums.empty()){
            find_pre = subsearch(pre_nums, target);
        }
        int find_post = subsearch(post_nums, target);
        if (find_pre != -1) return find_pre;
        if (find_post != -1) return find_post + left;

        return -1;
    }

    int subsearch(vector<int>& sub_nums, int target){
        int left = 0;
        int right = sub_nums.size() - 1;
        if (sub_nums.size() == 1 && sub_nums[0] == target) return 0;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (sub_nums[mid] > target){
                right = mid - 1;
            }
            else if (sub_nums[mid] < target){
                left = mid + 1;
            }
            else if (sub_nums[mid] == target){
                return mid;
            }
        }

        if (sub_nums[left] == target) return left;

        return -1;
        
    }
};


class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(nums[mid] >= nums[0]){
                l = mid;
            }
            else r = mid - 1;
        }
        if(target >= nums[0]){
            l = 0;
        }
        else{
            l = l + 1;
            r = n - 1;
        }
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= target){
                r = mid;
            }
            else l = mid + 1;
        }
        return (nums[r] == target ? r : -1);
    }
};

int main(){

    // vector<int> nums = {15,16,19,20,25,1,3,4,5,7,10,14};
    vector<int> nums = {1, 3};
    // vector<int> nums = {6,7,8,1,2,3,4,5};
    int target = 0;
    Solution s1;
    int res = s1.search(nums, target);

    return 0;
}