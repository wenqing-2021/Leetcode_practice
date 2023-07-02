/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        int middle = (nums2_size + nums1_size) / 2.0;
        queue<int> q;
        int size;
        if ((nums1_size + nums2_size) % 2 == 0){
            size = 2;
        }
        else{
            size = 1;
        }
        int num1_index = 0;
        int num2_index = 0;
        int res = 0;
        while (res <= middle){
            if (num1_index >= nums1_size){
                res++;
                q.push(nums2[num2_index]);
                num2_index++;
            }
            else if (num2_index >= nums2_size){
                res++;
                q.push(nums1[num1_index]);
                num1_index++;
            }
            else if (nums1[num1_index] > nums2[num2_index]){
                res++;
                q.push(nums2[num2_index]);
                num2_index++;
            }
            else{
                q.push(nums1[num1_index]);
                num1_index++;
                res++;
            }

            remove(q, size);
        }
        if (size == 2){
            int s1 = q.front();
            q.pop();
            int s2 = q.front();
            return (s1 + s2) / 2.0;
        }
        else{
            return q.front();
        }

        return 0;
    }

    void remove(queue<int>& q, int size){
        while (q.size() > size){
            q.pop();
        }
    }
};

int main(){
    vector<int> a = {1,3};
    vector<int> b = {2};
    Solution s1;
    double res = s1.findMedianSortedArrays(a, b);
    cout << res << endl;
    return 0;
}