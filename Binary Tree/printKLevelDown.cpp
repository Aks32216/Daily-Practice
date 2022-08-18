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
    
    vector<TreeNode*> rootPath;
    vector<int> res;
    
    bool getPath(TreeNode* root,TreeNode* target)
    {
        if(root==NULL)
            return false;
        if(root->val==target->val)
        {
            rootPath.push_back(root);
            return true;
        }
        bool x=getPath(root->left,target);
        if(x)
        {
            rootPath.push_back(root);
            return true;
        }
        x=getPath(root->right,target);
        if(x)
        {
            rootPath.push_back(root);
            return true;
        }
        return false;
    }
    
    void getLevelKDistance(TreeNode* root,int k,TreeNode* temp)
    {
        if(root==NULL || k<0 || temp==root)
            return;
        if(k==0)
        {
            res.push_back(root->val);
            return;
        }
        getLevelKDistance(root->left,k-1,temp);
        getLevelKDistance(root->right,k-1,temp);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        bool x=getPath(root,target);
        getLevelKDistance(rootPath[0],k,NULL);
        for(int i=1;i<rootPath.size();++i)
        {
            getLevelKDistance(rootPath[i],k-i,rootPath[i-1]);
        }
        return res;
    }
};