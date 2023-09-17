
/*
给定两个整数数组 preorder 和 inorder ，
其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
*/


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
#include <vector>
#include <map>
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
    int root_index = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); ++i){
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = buildTree(mp, 0, preorder.size()-1, preorder);
        return root;
    }

    TreeNode* buildTree(map<int, int>& mp, int l, int r, vector<int>& preorder){
        if (l <= r){
            int root_val = preorder[root_index];
            TreeNode* root = new TreeNode(root_val);
            root_index++;
            int left_index = mp.find(root_val)->second-1;
            int rigth_index = mp.find(root_val)->second+1;
            root->left = buildTree(mp, l, left_index, preorder);
            root->right = buildTree(mp, rigth_index, r, preorder);

            return root;
        }
        else return nullptr;
    }
};