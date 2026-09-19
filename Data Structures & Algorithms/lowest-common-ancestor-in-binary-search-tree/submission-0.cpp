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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int parent_val = root->val;
        int p_val = p->val;
        int q_val = q->val;

        if (p_val > parent_val && q_val > parent_val) {
            return lowestCommonAncestor(root->right, p,q);
        }
        else if (p_val < parent_val && q_val < parent_val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return root;
        }
    }
};
