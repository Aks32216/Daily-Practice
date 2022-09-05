// Brute Force
// find path from root to node of each of the given node
// compare the path and find the common node between both the paths

vector<TreeNode*> nodetorootpath(TreeNode* root,TreeNode* target)
{
    if(root==NULL)
    {
        vector<TreeNode*> path;
        return path;
    }
    if(root->val==target->val)
    {
        vector<TreeNode*> path;
        path.push_back(root);
        return path;
    }
    vector<TreeNode*> lcpath=nodetorootpath(root->left,target);
    vector<TreeNode*> rcpath=nodetorootpath(root->right,target);
    if(lcpath.size()>0)
    {
        lcpath.push_back(root);
        return lcpath;
    }
    else if(rcpath.size()>0)
    {
        rcpath.push_back(root);
        return rcpath;
    }
    else
    {
        vector<TreeNode*> path;
        return path;
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> firstpath=nodetorootpath(root,p);
    vector<TreeNode*> secondpath=nodetorootpath(root,q);
    for(auto i:firstpath)
        cout<<i->val<<" ";
    cout<<"\n";
    for(auto i:secondpath)
        cout<<i->val<<" ";
    cout<<"\n";
    TreeNode* val=new TreeNode(root->val);
    int i=firstpath.size()-1;
    int j=secondpath.size()-1;
    while(i>=0 && j>=0)
    {
        if(firstpath[i]==secondpath[j])
            val=firstpath[i];
        i--,j--;
    }
    return val;
}

// return the node if any node matches with given nodes
// if at any node both left and right child return non-null values that means
// at this node both are common in path
// if left node is non-null then return whatever is returned from the left
// if right node is non-null then return whatever is retruned from the right

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL)
       return NULL;
    if(root->val==p->val || root->val==q->val)
        return root;
    TreeNode* lc=lowestCommonAncestor(root->left,p,q);
    TreeNode* rc=lowestCommonAncestor(root->right,p,q);
    if(lc!=NULL && rc!=NULL)
        return root;
    else if(lc!=NULL)
        return lc;
    else 
        return rc;
}