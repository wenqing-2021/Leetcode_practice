
#include <vector>
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target_len = nums.size() / 2;
        map<int, int> count_map;
        for (int i = 0; i < nums.size(); ++i){
            if (count_map.find(nums[i]) == count_map.end()){
                count_map[nums[i]] = 1;
            }
            else{
                auto it = count_map.find(nums[i]);
                int val = it->second + 1;
                if (val > target_len){
                    return it->first;
                }
                count_map[nums[i]] = val;
            }
        }
        return nums[0];
    }
};

int main(){
    vector<int> nums = {1,2,3,2,2,2,5,4,2};
    Solution s1;
    int resutl = s1.majorityElement(nums);
    cout << resutl << endl;
    return 0;
}