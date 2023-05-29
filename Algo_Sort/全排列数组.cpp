#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<bool> used(len);
        recur(nums, used, len);
        return res;
    }
    void recur(vector<int>& nums, vector<bool>& used, int len){
        if (path.size() == len){
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i){
            if (!used[i]){
                path.push_back(nums[i]);
                used[i] = true;
                recur(nums, used, len);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};