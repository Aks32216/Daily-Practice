Node* remove(Node* root,int& m)
{
    if(root==NULL)
        return NULL;
    if(root->right==NULL)
    {
        m=root->data;
        return root->left;
    }
    root->right=remove(root->right,m);
    return root;
}

Node* solve(Node* root,int x)
{
    if(root==NULL)
        return NULL;
    if(root->data>x)
    {
        root->left=solve(root->left,x);
        return root;
    }
    else if(root->data<x)
    {
        root->right=solve(root->right,x);
        return root;
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
            return NULL;
        else if(root->left==NULL)
            return root->right;
        else if(root->right==NULL)
            return root->left;
        else
        {
            Node* temp=root->left;
            int m=INT_MAX;
            root->left=remove(temp,m);
            root->data=m;
            return root;
        }
    }
}

Node *deleteNode(Node *root, int X) {
    return solve(root,X);
}