/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof
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
#include <vector>
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
        if (root->val == p->val || root->val == q->val){
            return root;
        }
        if (root->left != nullptr){
            bool p_left = isInTree(root->left, p);
            bool q_left = isInTree(root->left, q);
            if (p_left && q_left){
                return lowestCommonAncestor(root->left, p, q);
            }
            
            return root;
        }
        if (root->right != nullptr){
            bool p_right = isInTree(root->right, p);
            bool q_right = isInTree(root->right, q);
            if (p_right && q_right){
                return lowestCommonAncestor(root->right, p, q);
            }
            
            return root;
        }

        return nullptr;
    }
    bool isInTree(TreeNode* root, TreeNode* node){
        if (root == nullptr) return false;
        if (node->val == root->val) return true;
        bool inleft = false, inright = false;
        if (root->left != nullptr){
            inleft = isInTree(root->left, node);
        }
        if (root->right != nullptr){
            inright = isInTree(root->right, node);
        }

        return inleft || inright;
    }

};

int main(){
    vector<int> a = {3,5,1,6,2,0,8,9999,9999,7,4};

    return 0;
}