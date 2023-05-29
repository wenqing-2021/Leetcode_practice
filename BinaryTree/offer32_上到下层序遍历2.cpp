/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> tmp;
        TreeNode* current_node;
        while(!q.empty()){
            int length = q.size();
            for (int i = 0; i < length; ++i){
                current_node = q.front();
                q.pop();
                tmp.push_back(current_node->val);
                if (current_node->left != NULL){
                    q.push(current_node->left);
                }
                if (current_node->right != NULL){
                    q.push(current_node->right);
                }
            }
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};