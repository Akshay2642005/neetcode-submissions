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
    int preorder_index = 0;
    int inorder_index = 0;

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit) {
        if (preorder_index >= preorder.size()) return nullptr;

        if (inorder[inorder_index] == limit) {
            inorder_index++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preorder_index++]);

        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, limit);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, INT_MAX);
    }
};
