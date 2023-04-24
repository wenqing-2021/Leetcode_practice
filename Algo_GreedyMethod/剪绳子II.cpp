// 范围更大，如果使用dp可能会超出范围(overflow), 利用greedy method
// 因为4可以拆成2*2，3拆开的话变小，所以不用拆。尽可能地拆3，不行再拆2

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3){
            return n - 1;
        }
        long long res = 1;
        if (n == 4) return 4;
        while (n > 4){
            n -= 3;
            res = res * 3 % 1000000007;
        }
        res = res * n % 1000000007;
        return int(res);
    }
};