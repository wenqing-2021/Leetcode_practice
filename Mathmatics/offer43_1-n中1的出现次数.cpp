


class Solution {
public:
    int countDigitOne(int n) {
        int high = n / 10;
        int cur = n - high*10;
        int low = 0;
        long long digit_num = 1;
        int res = 0;
        while (high != 0 || cur != 0){
            if (cur == 0){
                // 三种情况分别考虑，
                res += high * digit_num;
            }
            else if (cur == 1){
                res += high * digit_num + low + 1;
            }
            else if (cur > 1){
                res += (high + 1) * digit_num;
            }
            low += cur * digit_num;
            cur = high % 10;
            high = high / 10;
            digit_num = digit_num * 10;
        }
        return res;
    }
};