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

class node{
    public:
        int max=0;
        int leftInclined=-1;
        int rightInclined=-1;
};

node solve(TreeNode* root)
{
    if(root==NULL)
    {
        node n;
        return n;
    }
    node left=solve(root->left);
    node right=solve(root->right);
    node r;
    r.max=max({left.max,right.max,left.leftInclined+1,right.rightInclined+1});
    r.leftInclined=1+right.rightInclined;
    r.rightInclined=1+left.leftInclined;
    return r;
}

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        node p=solve(root);
        return p.max;
    }
};