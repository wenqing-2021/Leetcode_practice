
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
    int kthLargest(TreeNode* root, int k) {
        int res = 0;
        dfs(root, k, res);
        return res;
    }
    void dfs(TreeNode* root, int& k, int& res){
        // terminal condition
        if (root == NULL || k == 0){
            return;
        }
        dfs(root->right, k, res);
        k--;
        if (k == 0) res = root->val;
        dfs(root->left, k, res);
    }
};