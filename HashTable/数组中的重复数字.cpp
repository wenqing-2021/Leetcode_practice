#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> map;
        for (auto num_i : nums){
            if (map[num_i]){
                return num_i;
            }
            map[num_i] = true;
        }
        return -1;
    }
};