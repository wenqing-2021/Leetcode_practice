#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrace(nums, 0);
        return res;
    }
    void backtrace(vector<int>& nums, int k){
        res.push_back(path);
        for (int i = k; i < nums.size(); ++i){
            path.push_back(nums[i]);
            backtrace(nums, i+1);
            path.pop_back();
        }
    }
};