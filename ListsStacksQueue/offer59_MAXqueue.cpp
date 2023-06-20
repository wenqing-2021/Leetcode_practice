
#include <queue>
#include <deque>
using namespace std;

class MaxQueue {
public:
    queue<int> q; //store all value
    deque<int> max_q; // store the biggest and the second biggest value
    MaxQueue() {

    }
    
    int max_value() {
        if (!max_q.empty()) return max_q.front();
        else return -1;
    }
    
    void push_back(int value) {
        q.push(value);
        if (max_q.empty()) max_q.push_back(value);
        else{
            while (!max_q.empty() && value > max_q.back()){
                max_q.pop_back();
            }
            max_q.push_back(value);
        }
        return;
    }
    
    int pop_front() {
        if (!q.empty()){
            int value = q.front();
            q.pop();
            if (!max_q.empty() && value == max_q.front()) max_q.pop_front();
            return value;
        }
        return -1;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */