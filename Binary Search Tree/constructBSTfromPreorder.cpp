TreeNode* solve(vector<int>& preorder,int& idx,long min,long max)
    {
        if(idx>=preorder.size() || preorder[idx]<min || preorder[idx]>max)
            return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        root->left=solve(preorder,idx,min,root->val);
        root->right=solve(preorder,idx,root->val,max);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int start=0;
        return solve(preorder,start,LLONG_MIN,LLONG_MAX);
    }