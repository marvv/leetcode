/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* root, vector<int>& result) {
        if (root == NULL) return ;
        if (root->left) f(root->left, result);
        result.push_back(root->val);
        if (root->right) f(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        f(root, result);
        return result;
    }
};
