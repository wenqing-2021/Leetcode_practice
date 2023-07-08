
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class MedianFinder {
public:
    // 最大堆，存储左边一半的数据，堆顶为最大值
    priority_queue<int, vector<int>, less<int>> q_min;
    // 最小堆， 存储右边一半的数据，堆顶为最小值
    priority_queue<int, vector<int>, greater<int>> q_max;
    /** initialize your data structure here. */
    MedianFinder() {
    }

    // 维持堆数据平衡，并保证左边堆的最大值小于或等于右边堆的最小值
    void addNum(int num) {
        /*
         * 当两堆的数据个数相等时候，左边堆添加元素。
         * 采用的方法不是直接将数据插入左边堆，而是将数据先插入右边堆，算法调整后
         * 将堆顶的数据插入到左边堆，这样保证左边堆插入的元素始终是右边堆的最小值。
         * 同理左边数据多，往右边堆添加数据的时候，先将数据放入左边堆，选出最大值放到右边堆中。
         */
        if (q_min.size() == q_max.size()) {
            q_max.push(num);
            int top = q_max.top();
            q_max.pop();
            q_min.push(top);
        } else {
            q_min.push(num);
            int top = q_min.top();
            q_min.pop();
            q_max.push(top);
        }
    }
    
    double findMedian() {
        if (q_min.size() == q_max.size()) {
            return (q_min.top()+q_max.top())*1.0/2;
        } else {
            return q_min.top()*1.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(){
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1.0);
    obj->addNum(2.0);
    double para_2 = obj->findMedian();
    obj->addNum(3.0);
    double para_3 = obj->findMedian();
    return 0;
}