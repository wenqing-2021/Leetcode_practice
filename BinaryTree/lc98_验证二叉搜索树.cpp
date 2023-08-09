/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    long long maxVal = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }

    bool dfs(TreeNode* root){
        if (root == nullptr) return true;
        bool is_left = dfs(root->left);
        bool is_cur = true;
        if (maxVal < root->val) maxVal = root->val;
        else return false;
        bool is_right = dfs(root->right);
        return is_cur && is_left && is_right;
    }
};