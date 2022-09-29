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
    
    /*
    void solve(TreeNode* root,int curLevel,int val,int depth)
    {
        if(root==NULL)
            return;
        if(curLevel+1==depth)
        {
            TreeNode* left=new TreeNode(val,root->left,NULL);
            TreeNode* right=new TreeNode(val,NULL,root->right);
            root->left=left;
            root->right=right;
            return;
        }
        solve(root->left,curLevel+1,val,depth);
        solve(root->right,curLevel+1,val,depth);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL)
            return NULL;
        if(depth==1)
        {
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            newRoot->right=NULL;
            return newRoot;
        }
        solve(root,1,val,depth);
        return root;
    }
    */
    
    TreeNode* addOneRow(TreeNode* root,int val,int depth)
    {
        if(root==NULL)
        {
            return root;
        }
        if(depth==1)
        {
            TreeNode* newRoot=new TreeNode(val,root,NULL);
            return newRoot;
        }
        queue<TreeNode*> q;
        q.push(root);
        int curDepth=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto cur=q.front();
                q.pop();
                if(curDepth+1==val)
                {
                    TreeNode* left=new TreeNode(val,cur->left,NULL);
                    TreeNode* right=new TreeNode(val,NULL,cur->right);
                    cur->left=left;
                    cur->right=right;
                }
                else
                {
                    if(cur->left)
                        q.push(cur->left);
                    if(cur->right)
                        q.push(cur->right);
                }
            }
            curDepth++;
        }
        return root;
    }
};