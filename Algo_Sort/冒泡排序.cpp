#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> res = names;
        for (int i = 0; i < heights.size() - 1; ++i){
            for (int j = 0; j < heights.size() - 1 - i; ++j){
                if (heights[j] < heights[j+1]){
                    swap(heights[j], heights[j+1]);
                    swap(res[j], res[j+1]);
                }
            }
        }

        return res;
    }
};