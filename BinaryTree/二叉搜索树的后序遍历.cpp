#include <vector>
using namespace std;


class Solution {
public:
    bool traversal(vector<int>& postorder, int start, int end) {
        /* 递归终止条件 */
        if(start >= end) return true;
        int index = start;
        /* 中间处理逻辑 */
        while(postorder[index] < postorder[end]) index++;
        /* 记录分割点 */
       int midIndex = index;
        while(postorder[index] > postorder[end]) index++;
        /* 递归左右子树 */
        bool left = traversal(postorder, start, midIndex-1);
        bool right = traversal(postorder, midIndex, end-1);
        return index == end && left && right;
    }

    bool verifyPostorder(vector<int>& postorder) {
        return traversal(postorder, 0, postorder.size()-1);
    }
};