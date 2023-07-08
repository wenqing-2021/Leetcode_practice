
/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        TreeNode* res = isChild(p, q);
        if (res != nullptr){
            return res;
        }
        else if ((root->val > p->val && root->val < q->val) || 
                 (root->val < p->val && root->val > q->val)){
                     return root;
                 }
        else if (root->val == q->val || root->val == p->val){
            return root;
        }
        
        if (root->val > q->val && root->val > p->val){
            return lowestCommonAncestor(root->left, p, q);
        }

        return lowestCommonAncestor(root->right, p, q);
        
    }
    // check is child
    TreeNode* isChild(TreeNode* node_1, TreeNode* node_2){
        if (node_1->left == node_2 || node_1->right == node_2){
            return node_1;
        }
        if (node_2->left == node_1 || node_2->right == node_1){
            return node_2;
        }
        
        return nullptr;
    }
};