/*

给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

*/

#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> height(col, 0);
        int area = 0;
        for (int i = 0; i < row; ++i){
            stack<int> st;
            for (int j = 0; j < col; ++j){
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
                while(!st.empty() && height[st.top()] > height[j]){
                    int cur_height = height[st.top()];
                    st.pop();
                    int width = j;
                    if (!st.empty()) width = j - st.top() - 1;
                    area = max(area, cur_height * width);
                }
                st.push(j);
            }
            while(!st.empty()){
                int cur_height = height[st.top()];
                st.pop();
                int width = col;
                if (!st.empty()){
                    width = col - st.top() - 1;
                }
                area = max(area, cur_height * width);
            }
        }

        return area;
        
    }
};