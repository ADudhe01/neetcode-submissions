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
    int maxDiameter = 0;
    int diameter(TreeNode* root) {
        if (root == nullptr)
            return 0;

        // Get the height of left and right sub-trees
        int lheight = diameter(root->left);
        int rheight = diameter(root->right);

        if (maxDiameter < lheight + rheight) {
            maxDiameter = lheight + rheight;
        }

        return 1 + max(diameter(root->left), diameter(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return maxDiameter;
    }
};
