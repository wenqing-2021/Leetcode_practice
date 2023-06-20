class Solution {
public:
    int add(int a, int b) {
        while (b) {
            int carry = a & b; // 计算 进位
            a = a ^ b; // 计算 本位
            b = (unsigned)carry << 1;
        }
        return a;
    }
};