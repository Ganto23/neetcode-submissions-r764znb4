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
        deque<TreeNode*> q;
        q.push_front(root);
        vector<vector<int>> out;

        while (!q.empty()) {
            deque<TreeNode*> new_q;
            vector<int> cur_vec;

            while (!q.empty()) {
                auto cur = q.front(); q.pop_front();
                if (cur->left) new_q.push_back(cur->left);
                if (cur->right) new_q.push_back(cur->right);

                cur_vec.push_back(cur->val);
            }
            out.push_back(cur_vec);
            q = new_q;
        } 
        return out;
    }
};
