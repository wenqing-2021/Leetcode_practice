
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // stack
        // store the index number
        stack<int> st;
        int area = 0;
        for (int i = 0; i < height.size(); ++i){
            // 当高度开始上升的时候开始计算面积, while表示一层一层向上计算
            while(!st.empty() && height[st.top()] < height[i]){
                int current = st.top();
                st.pop();
                if (st.empty()) break;
                int left = st.top();
                int right = i;
                int h = min(height[left], height[right]) - height[current];
                int width = right - left - 1;
                area += width * h;
            }
            // 如果stack为空或者height还在下降，则push
            st.push(i);
        }

        return area;
    }
};

int main(){

    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s1;
    int result = s1.trap(a);
    cout << result << endl;

    return 0;
}