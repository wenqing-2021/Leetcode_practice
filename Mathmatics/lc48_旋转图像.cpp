/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/rotate-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first trans
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = i+1; j < matrix[0].size(); ++j){
                if (i != j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        
        // second mirror (left to right)
        int half_col_num = matrix[0].size() / 2;
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < half_col_num; ++j){
                swap(matrix[i][j], matrix[i][matrix.size() - j -1]);
            }
        }
    }
};