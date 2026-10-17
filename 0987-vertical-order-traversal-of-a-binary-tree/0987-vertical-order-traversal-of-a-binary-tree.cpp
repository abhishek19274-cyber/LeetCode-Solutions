class Solution {
public:
    struct cords {
        TreeNode* node;
        int vertical;
        int level;
        cords(TreeNode* node, int vertical, int level)
            : node(node), vertical(vertical), level(level) {}
    };
    struct mapper {
        int vertical;
        int level;
        multiset<int> s;
        mapper(int vertical, int level, int val)
            : vertical(vertical), level(level) {
            s.insert(val);
        }
    };
    void inordertraversal(TreeNode* root, queue<cords>& q, int vertical,
                          int level) {
        if (root == nullptr)
            return;
        inordertraversal(root->left, q, vertical - 1, level + 1);
        q.push(cords(root, vertical, level));
        inordertraversal(root->right, q, vertical + 1, level + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<cords> q;
        inordertraversal(root, q, 0, 0);
        vector<mapper> mp;
        while (!q.empty()) {
            cords temp = q.front();
            q.pop();
            bool found = false;
            for (auto& ele : mp) {
                if (ele.vertical == temp.vertical and ele.level == temp.level) {
                    ele.s.insert(temp.node->val);
                    found = true;
                    break;
                }
            }
            if (!found) {
                mp.push_back(mapper(temp.vertical, temp.level, temp.node->val));
            }
        }
        sort(mp.begin(), mp.end(), [](const mapper& a, const mapper& b) {
            if (a.vertical == b.vertical) {
                return a.level < b.level;
            }
            return a.vertical < b.vertical;
        });
        vector<vector<int>> result;
        for (int i = 0; i < (int)mp.size(); i++) {
            if (i == 0 || mp[i].vertical != mp[i - 1].vertical) {
                result.push_back({});
            }
            for (int v : mp[i].s) {
                result.back().push_back(v);
            }
        }
        return result;
    }
};