#include <vector>
#include <iostream>
#include <queue>
#include <stack>
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

TreeNode* BuildTree(vector<int> a, int index){
    TreeNode* root = nullptr;

	if (index < a.size() && a[index] != NULL){
		root = new TreeNode(a[index]);
		root->left = BuildTree(a, 2*index + 1);
		root->right = BuildTree(a, 2*index + 2);
	}
	return root;
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode*> left2right;
        stack<TreeNode*> right2left;
        int flag = 0; // 0 -> left2right, 1 -> right2left
        if (root == NULL){
            return res;
        }
        left2right.push(root);
        while (!left2right.empty() || !right2left.empty()){
            if (!flag){
                vector<int> left2right_vector;
                while (!left2right.empty()){
                    TreeNode* temp = left2right.top();
                    left2right.pop();
                    left2right_vector.push_back(temp->val);
                    if (temp->left != NULL){
                        right2left.push(temp->left);
                    }
                    if (temp->right != NULL){
                        right2left.push(temp->right);
                    }
                }
                res.push_back(left2right_vector);
                flag = 1;
                continue;
            }
            else{
                vector<int> right2left_vector;
                while (!right2left.empty()){
                    TreeNode* temp = right2left.top();
                    right2left.pop();
                    right2left_vector.push_back(temp->val);
                    if (temp->right != NULL){
                        left2right.push(temp->right);
                    }
                    if (temp->left != NULL){
                        left2right.push(temp->left);
                    }
                }
                res.push_back(right2left_vector);
                flag = 0;
                continue;
            }
        }

        return res;
    }
};


int main(){
    
    vector<int> array = {1,2,3,4,NULL,NULL,5};
	TreeNode* root;
	root = BuildTree(array, 0);
    Solution s1;
    vector<vector<int>> result = s1.levelOrder(root);
    for (auto v1 : result){
        for (auto num : v1){
            cout << num;
        }
        cout << endl;
    }
    return 0;
}