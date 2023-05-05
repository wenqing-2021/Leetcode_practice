
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int> que;

        //先对前k个数进行处理
        for(int i = 0; i < k; i ++)
        {
            while(!que.empty() && nums[i] > que.back())
            {
                que.pop_back();
            }
            que.push_back(nums[i]);
        }

        vector<int> res;
        //que中队首的数都是最大的，也就是第一个窗口的最大值
        res.push_back(que.front());


        //处理nums剩下的数
        for(int i = k; i < nums.size(); i++)
        {
            //如果窗口前端的数是最大值，就可以弹出队首的数，窗口里的次大值变成最大值
            if(nums[i - k] == que.front())
            {
                que.pop_front();
            }
            //同前k个数一样处理
            while(!que.empty() && nums[i] > que.back())
            {
                que.pop_back();
            }
            que.push_back(nums[i]);
            //每次把窗口里的最大值放入res中
            res.push_back(que.front());
        }

        return res;
    }
};

int main(){
    Solution solution;
    vector<int> a = {1,3,-1,-3,5,3,6,7};
    solution.maxSlidingWindow(a, 3);
    return 0;
}