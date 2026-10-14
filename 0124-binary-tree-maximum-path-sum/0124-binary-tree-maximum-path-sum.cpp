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
    int findmaxdown(TreeNode* root){
        if(root == nullptr)return INT_MIN;
        int left_max = max(0,findmaxdown(root->left));
        int right_max = max(0,findmaxdown(root->right));
        return root->val + max(left_max,right_max);
    }
    int maxPathSum(TreeNode* root) {
        if(root == nullptr)return -1;
        int left_gain = max(0,findmaxdown(root->left));
        int right_gain = max(0,findmaxdown(root->right));
        int current_path = root->val + left_gain + right_gain;
        int left_poss = root->left ? maxPathSum(root->left) : INT_MIN;
        int right_poss = root->right ? maxPathSum(root->right) : INT_MIN;
        return max({current_path,left_poss,right_poss});
    }
};