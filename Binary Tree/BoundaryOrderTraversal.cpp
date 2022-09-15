void getLeftBoundary(Node* root,vector<int>& res)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            return;
        else if(root->left)
        {
            res.push_back(root->data);
            getLeftBoundary(root->left,res);
        }
        else if(root->right){
            res.push_back(root->data);
            getLeftBoundary(root->right,res);
        }
    }
    
    void getLeaves(Node* root,vector<int>& res)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            res.push_back(root->data);
        getLeaves(root->left,res);
        getLeaves(root->right,res);
    }
    
    void getRightBoundary(Node* root,vector<int>& res)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            return;
        else if(root->right)
        {
            getRightBoundary(root->right,res);
            res.push_back(root->data);
        }
        else if(root->left){
            getRightBoundary(root->left,res);
            res.push_back(root->data);
        }
    }

    vector <int> boundary(Node *root)
    {
        vector<int> res;
        if(root==NULL)
            return res;
        if(root->left!=NULL || root->right!=NULL)
            res.push_back(root->data);
        getLeftBoundary(root->left,res);
        getLeaves(root,res);
        getRightBoundary(root->right,res);
        return res;
    }