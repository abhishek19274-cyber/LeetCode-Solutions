/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p )return p;
        if(root == q)return q;
        if(root == nullptr)return nullptr;
        auto la = (root->left) ? lowestCommonAncestor(root->left,p,q) : nullptr;
        auto ra = (root->right ) ? lowestCommonAncestor(root->right,p,q) : nullptr;
        if(la == nullptr and ra != nullptr)return ra;
        if(ra == nullptr and la != nullptr)return la;
        if(la!=nullptr and ra!=nullptr)return root;
        return nullptr;
    }
};