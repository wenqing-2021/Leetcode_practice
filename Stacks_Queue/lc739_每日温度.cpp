
/*
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/daily-temperatures
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int max_temp_index = st.top();
                st.pop();
                res[max_temp_index] = i - max_temp_index;
            }
            st.push(i);
        }
        return res;
    }
};