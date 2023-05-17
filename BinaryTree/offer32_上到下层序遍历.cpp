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
private:
    vector<int> result;
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == NULL){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target;
        while(q.size()){
            target = q.front();
            q.pop();
            result.push_back(target->val);
            if (target->left != NULL){
                q.push(target->left);
            }
            if (target->right != NULL){
                q.push(target->right);
            }
        }
        return result;
    }
};