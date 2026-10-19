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
        TreeNode* insertion_position(TreeNode* root, int val){
        if (val < root->val) {
            if (root->left == nullptr) return root;
            return insertion_position(root->left, val);
        } else {
            if (root->right == nullptr) return root;
            return insertion_position(root->right, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        TreeNode* node = insertion_position(root,val);
        if(node->val < val)node->right = new TreeNode(val);
        else node->left = new TreeNode(val);
        return root;
    }
};