TreeNode* solve(vector<int>& inorder,vector<int>& postorder,unordered_map<int,int>& mp,int& idx,int start,int end)
    {
        if(idx<0 || start>end)
            return NULL;
        TreeNode* root=new TreeNode(postorder[idx]);
        int pivot=mp[postorder[idx]];
        idx--;
        root->right=solve(inorder,postorder,mp,idx,pivot+1,end);
        root->left=solve(inorder,postorder,mp,idx,start,pivot-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();++i)
            mp[inorder[i]]=i;
        int i=postorder.size()-1,start=0,end=inorder.size()-1;
        return solve(inorder,postorder,mp,i,start,end);
    }