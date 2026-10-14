class Solution {
public:
    int helperfunc(TreeNode* root, int &maxi){
        if(root == nullptr) return 0;
        int left_sum = max(0, helperfunc(root->left, maxi));
        int right_sum = max(0, helperfunc(root->right, maxi));
        maxi = max(maxi, left_sum + right_sum + root->val);
        return root->val + max(left_sum, right_sum);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helperfunc(root, maxi);
        return maxi;
    }
};