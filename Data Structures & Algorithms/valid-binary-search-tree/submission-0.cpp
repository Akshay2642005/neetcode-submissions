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
   private:
    bool valid(TreeNode* node, int left, int right) {
        if (!node) return true;
        if (!(node->val < right && node->val > left)) return false;
        return (valid(node->left, left, node->val) && valid(node->right, node->val, right));
    };

   public:
    bool isValidBST(TreeNode* root) {
        if (!root) return 0;

        return valid(root, INT_MIN, INT_MAX);
    }
};
