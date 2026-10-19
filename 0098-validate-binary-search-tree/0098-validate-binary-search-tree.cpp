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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->left == nullptr and root->right == nullptr) return true;

        if (root->left != nullptr) {
            TreeNode* temp = root->left;
            while (temp->right != nullptr) temp = temp->right;
            if (root->val <= temp->val) return false;
        }
        if (root->right != nullptr) {
            TreeNode* temp = root->right;
            while (temp->left != nullptr) temp = temp->left;
            if (root->val >= temp->val) return false;
        }
        return isValidBST(root->left) and isValidBST(root->right);
    }
};