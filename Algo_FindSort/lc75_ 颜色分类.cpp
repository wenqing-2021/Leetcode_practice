#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        quicksort(nums, l, r);
    }
    void quicksort(vector<int>& nums, int l, int r){
        if (l >= r) return;
        int i = l;
        int j = r;
        while (i < j){
            while (i < j && nums[j] >= nums[l]) j--;
            while (i < j && nums[i] <= nums[l]) i++;
            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[l]);
        quicksort(nums, l, i-1);
        quicksort(nums, i+1, r);
        
    }
};