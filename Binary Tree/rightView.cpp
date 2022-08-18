// Recursive Solution

void solve(Node* root,int level,vector<int>& res)
{
    if(root==NULL)
        return;
    if(res.size()==level)
        res.push_back(root->data);
    solve(root->right,level+1,res);
    solve(root->left,level+1,res);
}

vector<int> rightView(Node *root)
{
   vector<int> res;
   solve(root,0,res);
   return res;
}


// Iterative Solution

vector<int> rightView(Node *root)
{
   vector<int> res;
   if(root==NULL)
    return res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;++i)
        {
            auto cur=q.front();
            q.pop();
            if(i==n-1)
                res.push_back(cur->data);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
    }
    return res;
}