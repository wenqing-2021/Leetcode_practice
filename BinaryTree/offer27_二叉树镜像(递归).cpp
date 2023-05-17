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
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root){
            return NULL;
        }
        // terminal condition
        if (!root->left && !root->right) return root;
        // recursion
        TreeNode* right = NULL;
        TreeNode* left = NULL;
        if (root->right){
            right = mirrorTree(root->right);
        }
        if (root->left){
            left = mirrorTree(root->left);
        }
        root->left = right;
        root->right = left;

        return root;
    }
};