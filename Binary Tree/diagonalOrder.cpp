void solve(Node* root,int diagonal,map<int,vector<int> >& mp)
{
    if(root==NULL)
        return;
    mp[diagonal].push_back(root->data);
    solve(root->left,diagonal+1,mp);
    solve(root->right,diagonal,mp);
}

vector<int> diagonal(Node *root)
{
   vector<int> res;
   if(root==NULL)
    return res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            auto cur=q.front();
            q.pop();
            while(cur)
            {
                res.push_back(cur->data);
                if(cur->left)
                    q.push(cur->left);
                cur=cur->right;
            }
        }
    }
    return res;
}