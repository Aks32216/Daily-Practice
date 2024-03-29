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
    
    bool isEqualSubtree(TreeNode* root,TreeNode* subRoot)
    {
        if(root==NULL || subRoot==NULL)
            return root==subRoot;
        return (root->val==subRoot->val) && isEqualSubtree(root->left,subRoot->left) && isEqualSubtree(root->right,subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)
            return false;
        if(root->val==subRoot->val && isEqualSubtree(root,subRoot))
            return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};