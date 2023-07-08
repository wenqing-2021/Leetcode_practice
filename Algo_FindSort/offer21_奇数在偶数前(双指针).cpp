#include <vector>
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int length = nums.size();
        for (int i =0, j=length - 1; i < j;){
            bool left = nums[i] % 2 == 1;
            bool right = nums[j] % 2 == 0;
            if (left && right){
                i++;
                j--;
            }
            else{
                if (left & (!right)){
                    i++;
                }
                if (!left & right){
                    j--;
                }
                if ((!left) & (!right)){
                    swap(nums[i], nums[j]);
                    i++;
                    j--;
                }
            }
        }
        return nums;
    }
};