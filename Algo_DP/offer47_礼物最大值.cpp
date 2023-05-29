#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        // initial
        vector<vector<int>> gift_value(row, vector<int> (col, 0));
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                if (i == 0 && j > 0){
                    gift_value[i][j] = gift_value[i][j-1] + grid[i][j];
                }
                else if (i == 0 && j == 0){
                    gift_value[i][j] = grid[i][j];
                }
                else if (j == 0 && i > 0){
                    gift_value[i][j] = gift_value[i-1][j] + grid[i][j];
                }
                else{
                    gift_value[i][j] = grid[i][j] + max(gift_value[i-1][j], gift_value[i][j-1]);
                }
            }
        }
        return gift_value[row-1][col-1];
    }
};