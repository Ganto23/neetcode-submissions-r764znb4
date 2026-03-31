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
    int kthSmallest(TreeNode* root, int k) {
        if (!root){
            return 0;
        }
        vector<int> res_vect;
        recur(root, res_vect);
        return res_vect[k-1];
    }
    void recur(TreeNode* node, vector<int>& res_vect) {
        if (!node){
            return;
        }

        recur(node->left, res_vect);
        res_vect.push_back(node->val);
        recur(node->right, res_vect);

    }
};
