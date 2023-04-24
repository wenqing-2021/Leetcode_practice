/*
编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。
*/

// n-1以后，1右侧是0的会变成1，1会变成0.取&逻辑运算后，会把1给消掉，直到n=0退出循环。

#include <stdint.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n){
            res += 1;
            n &= n - 1;
        }
        return res;
    }
};