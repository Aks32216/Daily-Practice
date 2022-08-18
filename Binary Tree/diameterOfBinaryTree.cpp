int m=INT_MIN;
    
    int diameter(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int h1=diameter(root->left);
        int h2=diameter(root->right);
        m=max(m,h1+h2);
        return max(h1,h2)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int x=diameter(root);
        return m;
    }