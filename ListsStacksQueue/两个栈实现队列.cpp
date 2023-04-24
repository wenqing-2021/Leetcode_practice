
#include <stack>
using namespace std;

class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    CQueue() {
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        // put the stack1 into stack2 and delete the top of stack2
        if (stack2.empty()){
            while ( !stack1.empty()){
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        if (stack2.empty()){
            return -1;
        }
        int res = stack2.top();
        stack2.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */