/*


给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
using namespace std;




class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // store the island number
        int res = 0;
        // 如果grid[i][j]为1，通过递归将这个岛屿所有的1变为0，res++;
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                if (grid[i][j] == '1'){
                    // remove the island
                    transform(grid, i, j);
                    res++;
                }
            }
        }

        return res;
    }

    void transform(vector<vector<char>>& grid, int i, int j){
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0){
            return;
        }
        if (grid[i][j] == '1'){
            grid[i][j] = '0';
            if (j+1 < grid[0].size() && grid[i][j+1] == '1'){
                transform(grid, i, j+1);
            }
            if (j-1>=0 && grid[i][j-1] == '1'){
                transform(grid, i, j-1);
            }
            if (i-1>=0 && grid[i-1][j] == '1'){
                transform(grid, i-1, j);
            }
            if (i+1 < grid.size() && grid[i+1][j] == '1'){
                transform(grid, i+1, j);
            }
        }

        return;
    }
};