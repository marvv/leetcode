class Solution {
public:
    bool validateChild(bool gt, int val, TreeNode* root) {
        if (root == NULL) return true;
        if (gt) {
            if (root->val <= val) return false;
        } else {
            if (root->val >= val) return false;
        }
        
        return validateChild(gt, val, root->left) && validateChild(gt, val, root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        if (!validateChild(false,root->val, root->left)) return false;
        if (!validateChild(true,root->val, root->right)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
