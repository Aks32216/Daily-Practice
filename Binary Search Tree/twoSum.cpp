// Using Inorder Traversal

void solve(TreeNode* root,vector<int>& inorder)
    {
        if(root==NULL)
            return;
        solve(root->left,inorder);
        inorder.push_back(root->val);
        solve(root->right,inorder);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        solve(root,inorder);
        int i=0,j=inorder.size()-1;
        while(i<j)
        {
            int sum=inorder[i]+inorder[j];
            if(sum==k)
                return true;
            else if(sum<k)
                i++;
            else
                j--;
        }
        return false;
    }

    // Using Recursion

    bool find(int target,TreeNode* root,int dup)
    {
        if(root==NULL)
            return false;
        if(root->val==target && root->val!=dup)
            return true;
        if(root->val<target)
            return find(target,root->right,dup);
        else if(root->val>target)
            return find(target,root->left,dup);
        else
            return false;
    }
    
    bool solve(TreeNode* root,TreeNode* mainroot,int k)
    {
        if(root==NULL)
            return false;
        if(find(k-root->val,mainroot,root->val))
            return true;
        else
            return solve(root->left,mainroot,k) || solve(root->right,mainroot,k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        return solve(root,root,k);
    }