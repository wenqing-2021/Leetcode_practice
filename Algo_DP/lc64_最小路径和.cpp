
/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j]
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                if (i == 0 && j == 0) continue;
                if (i == 0){
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                    continue;
                }
                if (j == 0){
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                    continue;
                }
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }

        return dp[grid.size()-1][grid[0].size()-1];
    }
};