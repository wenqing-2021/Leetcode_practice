/*

输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int slow = 1;
        int fast = 1;
        int sum = 1;
        while(slow <= fast){
            // 移动右侧区间
            while (sum < target){
                fast++;
                sum += fast;
            }
            // 如果找到目标数组
            if (sum == target){
                vector<int> temp_vec;
                for (int i = slow; i <= fast; ++i){
                    temp_vec.push_back(i);
                }
                // 去除自身的数值
                if (temp_vec.size() != 1){
                    res.push_back(temp_vec);
                }
                sum -= slow;
                slow++;
            }
            // 如果数组和比目标值大，移动左侧区间
            else{
                sum -= slow;
                slow++;
            }
        }
        return res;
    }
};
