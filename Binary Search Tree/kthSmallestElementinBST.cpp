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
    void solve(TreeNode* root,vector<int>& inorder)
    {
        if(root==NULL)
            return;
        solve(root->left,inorder);
        inorder.push_back(root->val);
        solve(root->right,inorder);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        solve(root,inorder);
        return inorder[k-1];
    }
    
    
    void solve(TreeNode* root,int& k,int& smallest)
    {
        if(root==NULL)
            return;
        solve(root->left,k,smallest);
        k--;
        if(k==0)
            smallest=root->val;
        solve(root->right,k,smallest);
    }
    
    int kthSmallest(TreeNode* root,int k)
    {
        int smallest=0;
        solve(root,k,smallest);
        return smallest;
    }
    */
    
    int kthSmallest(TreeNode* root,int k)
    {
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            auto cur=s.top();
            if(cur->left)
            {
                TreeNode* temp=cur->left;
                cur->left=NULL;
                s.push(temp);
            }
            else
            {
                k--;
                if(k==0)
                    return cur->val;
                s.pop();
                if(cur->right)
                    s.push(cur->right);
            }
        }
        return -1;
    }
};