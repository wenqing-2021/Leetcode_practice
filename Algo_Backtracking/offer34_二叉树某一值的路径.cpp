#include <vector>
using namespace std;

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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        recur(root, target);
        return res;
    }
    void recur(TreeNode* root, int target){
        if (root == nullptr){
            return;
        }
        path.push_back(root->val);
        if (target == root->val && !root->left && !root->right){
            res.push_back(path);
        }
        target -= root->val;
        recur(root->left, target);
        recur(root->right, target);
        path.pop_back();
    }
private:
    vector<vector<int>> res;
    vector<int> path;
};