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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        if(!root)return result;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                level.push_back(node->val);
            }
            result.push_back(level);
        }
        return result;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode* > q;
        result = levelOrder(root);
        for(int i =0;i<result.size();i++){
            if(i%2!=0){
                reverse(result[i].begin(),result[i].end());
            }
        }
        return result;
    }
};