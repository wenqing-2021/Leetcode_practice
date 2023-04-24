#include <vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0){
            return false;
        }
        int j = matrix[0].size() - 1;
        int i = 0;
        while(j>=0 && i < matrix.size()){
            if (matrix[i][j] > target){
                j--;
            }
            else if(matrix[i][j] == target){
                return true;
            }
            else{
                i++;
            }
        }
        return false;
    }
};