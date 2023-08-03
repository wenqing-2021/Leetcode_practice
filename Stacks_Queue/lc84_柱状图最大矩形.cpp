


/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int width;
        int area;
        int size = heights.size();
        for (int i = 0; i < size; ++i){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int current_height = heights[st.top()];
                st.pop();
                width = i;
                if (!st.empty()){
                    width = i - st.top() - 1;
                }

                area = max(area, current_height * width);
            }
            st.push(i);
        }

        while(!st.empty()){
            int height = heights[st.top()];
            st.pop();
            width = size;
            if (!st.empty()){
                width = size - st.top() - 1;
            }
            area = max(area, width * height);
            
        }

        return area;
    }
};