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
    void insert_node(TreeNode* root, int val) {
        if (val < root->val) {
            if (root->left == nullptr) {
                root->left = new TreeNode(val);
                return;
            }
            insert_node(root->left, val);
        } 
        else {
            if (root->right == nullptr) {
                root->right = new TreeNode(val);
                return;
            }
            insert_node(root->right, val);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)return new TreeNode;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1 ;i < preorder.size() and preorder.size()>1;i++){
            insert_node(root,preorder[i]);
        }
        return root;
    }
};