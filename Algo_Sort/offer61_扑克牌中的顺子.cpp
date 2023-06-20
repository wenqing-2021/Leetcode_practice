
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero_num = 0;
        for (int i = 0; i < nums.size()-1; ++i){
            if (nums[i] == 0){
                zero_num++;
                continue;
            }
            int diff = nums[i+1] - nums[i];
            if (diff == 0){
                return false;
            }
            else if (diff == 1){
                continue;
            }
            else{
                zero_num -= (diff - 1);
                if (zero_num < 0){
                    return false;
                }
            }
        }

        return true;
    }
};