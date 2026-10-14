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
class Solution {
public:
    bool mirrorTree(TreeNode* left,TreeNode* right){
        if(left == nullptr and right == nullptr )return true;
        if(left == nullptr and right)return false;
        if(right == nullptr and left)return false;
        if(left->val != right->val)return false;
        return mirrorTree(left->left,right->right) and mirrorTree(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return mirrorTree(root->left,root->right);
    }
};