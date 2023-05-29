#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.empty() && popped.empty()){
            return true;
        }
        stack<int> st;
        int j = 0;

        // push 
        for (int i = 0; i < pushed.size(); ++i){
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }

        // pop
        while (j < popped.size() && popped[j] == st.top()){
            st.pop();
            j++;
        }
        if (st.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    Solution s1;
    vector<int> pushed = {0,1};
    vector<int> poped = {0,1};
    bool flag = s1.validateStackSequences(pushed, poped);
    cout << flag << endl;
    return 0;
}