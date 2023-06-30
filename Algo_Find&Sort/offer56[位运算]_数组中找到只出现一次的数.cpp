

/*

符号	描述	运算规则
&	与	两个位都为1时，结果才为1
&	与	两个位都为1时，结果才为1
|	或	两个位都为0时，结果才为0
^	异或	两个位相同为0，相异为1
~	取反	0变1，1变0
<<	左移	各二进位全部左移若干位，高位丢弃，低位补0
>>	右移	各二进位全部右移若干位，对无符号数，高位补0，有符号数，各编译器处理方法不一样，有的补符号位（算术右移），有的补0（逻辑右移）
*/


#include <vector>
using namespace std;


class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0, y = 0, n = 0, m = 1;
        for(int num : nums)         // 1. 遍历异或
            n ^= num;
        while((n & m) == 0)         // 2. 循环左移，计算 m, 找到两个不同的数，不同的那一位
            m <<= 1;
        for(int num : nums) {       // 3. 遍历 nums 分组，因为有两个数不同，所以肯定被分到2组
            if(num & m) x ^= num;   // 4. 当 num & m != 0
            else y ^= num;          // 4. 当 num & m == 0
        }
        return vector<int> {x, y};  // 5. 返回出现一次的数字
    }
};

