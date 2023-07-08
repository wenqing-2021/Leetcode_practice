
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int pack = 2 * numRows - 2;
        int size = s.size();
        
        vector<vector<char>> array_char = getArray(size, pack, numRows);

        for (int i = 0; i < size; ++i){
            // 整数部分
            int char_num1 = (i+1) / pack;
            // 余数部分
            int char_num2 = (i+1) % pack;
            int row_num;
            int col_num;
            if (char_num2 == 0){
                row_num = 1;
                col_num = char_num1 * (numRows - 1) - 1;
            }
            else if (char_num2 <= numRows){
                row_num = char_num2 - 1;
                col_num = char_num1 * (numRows - 1);
            }
            else{
                row_num = numRows - 1 - (char_num2 - numRows);
                col_num = char_num1 * (numRows - 1) + (char_num2 - numRows);
            }

            array_char[row_num][col_num] = s[i];

        }
        string res;
        for (int j = 0; j < array_char.size(); ++j){
            for (int k = 0; k < array_char[0].size(); ++k){
                if (array_char[j][k] == ' ') continue;
                res.push_back(array_char[j][k]);
            }
        }

        return res;
    }

    vector<vector<char>> getArray(int size, int pack, int numRows){
        // 整数部分
        int num_1 = size / pack;
        // 余数部分
        int num_2 = size % pack;
        // 构造矩阵
        if (num_2 == 0){
            return vector<vector<char>>(numRows, vector<char>(num_1 * (numRows-1), ' '));
        }
        else if (num_2 <= numRows){
            return vector<vector<char>>(numRows, vector<char>(num_1 * (numRows-1) + 1, ' '));
        }
        else{
            return vector<vector<char>>(numRows, vector<char>(num_1 * (numRows-1) + 1 + num_2 - numRows, ' '));
        }
    }
};