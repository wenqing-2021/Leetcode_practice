#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> nums_map;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i){
            int dev = target - nums[i];
            if (nums_map.find(dev) != nums_map.end()){
                res.push_back(nums_map.find(dev)->second);
                res.push_back(i);
                return res;
            }
            nums_map[nums[i]] = i;
        }
        return res;
    }
};