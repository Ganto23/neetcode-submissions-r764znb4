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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr){
            return nullptr;
        }
        TreeNode* croot = root;
        TreeNode* cleft = croot->left;
        TreeNode* cright = croot->right;
        croot->left = invertTree(cright);
        croot->right = invertTree(cleft);
        return croot;

    }
};


