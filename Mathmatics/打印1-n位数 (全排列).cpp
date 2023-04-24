// 这个题不适合用dfs进行递归，时间会很慢



#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        int max_num = std::pow(10, n) - 1;
        vector<int> res(max_num);
        for (int i = 1, j = max_num; i <= j; i++, j--){
            res[i - 1] = i;
            res[j - 1] = j;
        }
        return res;
    }
};