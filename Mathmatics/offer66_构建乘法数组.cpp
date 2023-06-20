
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty()) return {};
        int length = a.size();
        vector<int> res(length, 0);
        vector<int> pre_prod(length, 0);
        vector<int> post_prod(length, 0);
        pre_prod[0] = a[0];
        post_prod[length - 1] = a[length - 1];
        for (int i = 1; i < length; ++i){
            pre_prod[i] = pre_prod[i-1] * a[i];
            post_prod[length - 1 - i] = post_prod[length-i] * a[length-1-i];
        }
        res[0] = post_prod[1];
        for (int j = 1; j < length; ++j){
            if (j != length - 1){
                res[j] = pre_prod[j-1] * post_prod[j+1];
            }
            else{
                res[j] = pre_prod[j-1];
            }
        }

        return res;
    }
};