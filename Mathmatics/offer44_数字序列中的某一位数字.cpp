
#include <vector>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long long start = 1;
        int digit_num = 1;
        long long count = 9;
        // find the range
        while (n > count){
            n -= count;
            start = pow(10, digit_num);
            digit_num += 1;
            count = 9 * start * digit_num;
        }
        int num = start + (n - 1) / digit_num;
        string num_str = to_string(num);
        int bit = (n - 1) % digit_num;
        int res = num_str[bit] - '0';
        return res;
    }
};

int main(){
    Solution s1;
    int a = s1.findNthDigit(3);
    cout << a << endl;
    return 0;
}