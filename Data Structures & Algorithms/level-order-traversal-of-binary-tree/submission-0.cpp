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
        vector<vector<int>> res;
        levelOrderRec(root,0,res);
        return res;
    }
private:
    void levelOrderRec(TreeNode* root, int depth, vector<vector<int>>& res){
        if (!root){
            return;
        }
        if (res.size() <= depth){
            res.push_back({});
        }

        res[depth].push_back(root->val);
        levelOrderRec(root->left, depth+1, res);
        levelOrderRec(root->right, depth+1, res);
    }
};
