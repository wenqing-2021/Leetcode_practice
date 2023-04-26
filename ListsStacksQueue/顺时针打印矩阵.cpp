#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return {};
        }
        vector<int> res(matrix.size() * matrix[0].size());
        int l = 0, b = matrix.size() - 1,r = matrix[0].size() - 1,t = 0;
        int num = matrix[0].size() * matrix.size();
        int k = 0;
        while (k<num){
            for (int i = l; i <= r & k < num; i++) {
                res[k] = matrix[t][i];
                k++;
            }
            t++;
            for (int i = t; i <= b & k < num; i++) {
                res[k] = (matrix[i][r]);
                k++;
            }
            r--;
            for (int i = r; i >= l & k < num; i--) {
                res[k] = (matrix[b][i]);
                k++;
            }
            b--;
            for (int i = b; i >= t & k < num; i--) {
                res[k] = (matrix[i][l]);
                k++;
            }
            l++;
        }

        return res;
    }
};