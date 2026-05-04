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
        if (!root) return {};

        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        int currLevel = 0;
        vector<int> vec;
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            if (node->left) q.push({node->left, level + 1});
            if (node->right) q.push({node->right, level + 1});

            vec.push_back(node->val);

            if (q.empty() || q.front().second != currLevel) {
                currLevel++;
                ans.push_back(vec);
                vec.clear();
            }
        }

        return ans;
    }
};
