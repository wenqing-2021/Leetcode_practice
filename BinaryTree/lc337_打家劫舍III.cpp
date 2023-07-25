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

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = recur(root);
        return max(result[0], result[1]);
    }

    vector<int> recur(TreeNode* cur){
        // first item: not steal current node, second item: steal current node
        if (cur == nullptr) return vector<int>{0, 0};
        vector<int> left = recur(cur->left);
        vector<int> right = recur(cur->right);
        // steal current node
        int value_2 = cur->val + left[0] + right[0];
        // not steal current node
        int value_1 = max(left[1], left[0]) + max(right[0], right[1]);
        
        return {value_1, value_2};
    }
};