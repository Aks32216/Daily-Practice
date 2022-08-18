// Recursive Way

TreeNode* prev=NULL;
    
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }

    // Iterative Way

    void flatten(TreeNode* root) {
       if(root==NULL)
           return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            auto cur=s.top();
            s.pop();
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
            cur->left=NULL;
            if(!s.empty())
                cur->right=s.top();
        }
    }