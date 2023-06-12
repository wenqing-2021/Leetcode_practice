
#include <vector>
#include <algorithm>
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
    bool isBalanced(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        int left_depth = MaxDepth(root->left);
        int right_depth = MaxDepth(root->right);
        bool current_node = false;
        if (abs(left_depth - right_depth) <= 1){
            current_node = true;
        }
        
        return current_node && isBalanced(root->left) && isBalanced(root->right);
    }
    int MaxDepth(TreeNode* root){
        if (root == NULL){
            return 0;
        }
        return max(MaxDepth(root->left), MaxDepth(root->right))+1;
    }
};