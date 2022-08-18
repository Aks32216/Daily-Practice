TreeNode* solve(vector<int>& preorder,vector<int>& inorder,unordered_map<int,int>& mp,int& i,int start,int end)
    {
        if(i>=preorder.size() || start>end)
            return NULL;
        TreeNode* root=new TreeNode(preorder[i]);
        int index=mp[preorder[i]];
        i++;
        root->left=solve(preorder,inorder,mp,i,start,index-1);
        root->right=solve(preorder,inorder,mp,i,index+1,end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();++i)
        {
            mp[inorder[i]]=i;
        }
        int i=0,start=0,end=inorder.size()-1;
        return solve(preorder,inorder,mp,i,start,end);
    }