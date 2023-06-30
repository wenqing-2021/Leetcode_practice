#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> q;
        for(int i=0;i<k;i++)
        {
            q.emplace(nums[i],i);
        }
        vector<int> ans;
        ans.push_back(q.top().first);
        for(int i=k;i<n;i++)
        {
            q.emplace(nums[i],i);
            while(i-q.top().second+1>k)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};


int main(){
    vector<int> test_num = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution s1;
    vector<int> result = s1.maxSlidingWindow(test_num, k);

}