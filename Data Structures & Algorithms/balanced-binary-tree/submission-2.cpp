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
    int height(TreeNode* root) {
        if (!root) return 0;

        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        int hleft = height(root->left);
        int hright = height(root->right);

        bool currNodeBalanced = abs(hleft - hright) <= 1;
        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);
        
        return currNodeBalanced && leftBalanced && rightBalanced;
    }
};
