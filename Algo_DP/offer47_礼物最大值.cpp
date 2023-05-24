
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row_num = grid.size();
        int col_num = grid[0].size();
        vector<vector<int>> dp(row_num, vector<int> (col_num, 0));
        // dp
        for (int i = 0; i < row_num; ++i){
            for (int j = 0; j < col_num; ++j){
                if (i == 0 && j == 0){
                    dp[0][0] = grid[0][0];
                    continue;
                }
                else if (i == 0 && j != 0){
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                }

                else if (i !=0 && j == 0){
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                }
                else{
                    dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[row_num-1][col_num-1];
    }
};

int main(){



    return 0;
}