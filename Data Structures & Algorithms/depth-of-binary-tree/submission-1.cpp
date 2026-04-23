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
    int recur(TreeNode* root, int current_depth) {
        if (!root) return current_depth;

        current_depth++;
        return std::max(recur(root->left, current_depth), recur(root->right, current_depth));
    }

    int maxDepth(TreeNode* root) {
        return recur(root, 0);
    }
};
