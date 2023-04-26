/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        bool res = CompareSubTree(root->left, root->right);
        return res;
    }
private:
    bool CompareSubTree(TreeNode* left, TreeNode* right){
        if (!left && !right) return true;
        if (!(left && right)) return false;
        if (left->val != right->val) return false;
        bool res1 = CompareSubTree(left->left, right->right);
        bool res2 = CompareSubTree(left->right, right->left);

        return (res1 && res2);
    }
};