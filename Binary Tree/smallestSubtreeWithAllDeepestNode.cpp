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
    TreeNode* ans;
    
    int findHeight(TreeNode* root){
        if(root==NULL)
            return 0;
        int left=findHeight(root->left);
        int right=findHeight(root->right);
        return max(left,right)+1;
    }
    
    void solve(TreeNode* root)
    {
        if(root==NULL)
            return;
        int left=findHeight(root->left);
        int right=findHeight(root->right);
        if(left==right)
        {
            ans=root;
            return;
        }
        else if(left>right)
            solve(root->left);
        else
            solve(root->right);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        solve(root);
        return ans;
    }
    */
    
    void findLeftAndRightMost(TreeNode* root,int level,int& maxDepth){
        if(root==NULL)
            return;
        if(level>maxDepth){
            p=root;
            q=root;
            maxDepth=level;
        }
        else if(level==maxDepth){
            q=root;
        }
        findLeftAndRightMost(root->left,level+1,maxDepth);
        findLeftAndRightMost(root->right,level+1,maxDepth);
    }
    TreeNode* p;
    TreeNode* q;
    
    TreeNode* LCA(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL)
            return NULL;
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        TreeNode* lc=LCA(root->left,p,q);
        TreeNode* rc=LCA(root->right,p,q);
        if(lc!=NULL && rc!=NULL)
            return root;
        else if(lc!=NULL)
            return lc;
        else
            return rc;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root){
        int level=0,maxDepth=-1;
        findLeftAndRightMost(root,level,maxDepth);
        return LCA(root,p,q);
        cout<<p->val<<" "<<q->val<<"\n";
        return NULL;
    }
};