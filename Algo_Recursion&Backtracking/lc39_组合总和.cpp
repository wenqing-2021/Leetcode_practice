/*
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtracking(candidates, target, temp);

        return res;
    }
    void backtracking(vector<int>& cs, int target, vector<int>& temp){
        if (target == 0){
            res.push_back(temp);
            return;
        }
        if (target < cs[0]) return;

        for (int i = 0; i < cs.size(); ++i){
            int num_i = cs[i];
            if (num_i > target) continue;
            temp.push_back(num_i);
            target -= num_i;
            vector<int> temp_cs(cs.begin()+i, cs.end());
            backtracking(temp_cs, target, temp);
            temp.pop_back();
            target += num_i; 
        }

        return;
    }
};