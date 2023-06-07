
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode* root, int& res){
        // terminal condition
        if (root == NULL){
            return;
        }
        int left_depth = res;
        int right_depth = res;
        dfs(root->left, left_depth);
        dfs(root->right, right_depth);
        // 左右较深的一个加上自己这一层的厚度
        res = max(left_depth, right_depth)+1;
    }
};