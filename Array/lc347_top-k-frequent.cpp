

#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> dict;
        for (int i = 0; i < nums.size(); ++i){
            dict[nums[i]]++;
        }
        for (auto &it : dict){
            if (res.empty()){
                res.push_back(it.first);
            }
            else{
                // order
                int i = 0;
                while(i < res.size() && it.second < dict[res[i]]){
                    i++;
                }
                res.insert(res.begin() + i, it.first);
            }
        }
        vector<int> final_vec(res.begin(), res.begin() + k);
        return final_vec;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    //1.map记录元素出现的次数
        unordered_map<int,int>map;//两个int分别是元素和出现的次数
        for(auto& c:nums){
            map[c]++;
        }
    //2.利用优先队列，将出现次数排序
        //自定义优先队列的比较方式，小顶堆
        struct myComparison{
            bool operator()(pair<int,int>&p1,pair<int,int>&p2){
                return p1.second>p2.second;//小顶堆是大于号
            }
        };
        //创建优先队列
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComparison> q;
        //遍历map中的元素
        //1.管他是啥，先入队列，队列会自己排序将他放在合适的位置
        //2.若队列元素个数超过k，则将栈顶元素出栈（栈顶元素一定是最小的那个）
        for(auto& a:map){
            q.push(a);
            if(q.size()>k){
               q.pop(); 
            }
        }
        //将结果导出
        vector<int>res;
        while(!q.empty()){
            res.emplace_back(q.top().first);
            q.pop();
        }
        return res;

    }
};

int main(){
    vector<int> a = {1,1,1,2,2,3};
    int k = 2;
    Solution s1;
    vector<int> res = s1.topKFrequent(a, k);
}