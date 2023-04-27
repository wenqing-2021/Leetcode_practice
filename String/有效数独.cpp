
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0};
        int col[9][10] = {0};
        int box[9][10] = {0};
        for(int i=0; i<9; i++){
            for(int j = 0; j<9; j++){
                // 遍历到第i行第j列的那个数,我们要判断这个数在其所在的行有没有出现过，
                // 同时判断这个数在其所在的列有没有出现过
                // 同时判断这个数在其所在的box中有没有出现过
                if (board[i][j] == '.'){
                    continue;
                }
                int num = (board[i][j] - '0'); // -'0' 转换成int，不能用(int)转换
                if(row[i][num]) return false; 
                if(col[j][num]) return false;
                // compute box number
                int box_i = (i / 3) * 3 + (j / 3);
                if(box[box_i][num]) return false;

                row[i][num] = 1;// 之前都没出现过，现在出现了，就给它置为1，下次再遇见就能够直接返回false了。
                col[j][num] = 1;
                box[box_i][num] = 1;
            }
        }
        return true;
    }
};