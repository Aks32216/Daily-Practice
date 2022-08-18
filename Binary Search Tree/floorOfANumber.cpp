void solve(TreeNode<int>* root,int ele,int& floor)
{
    if(root==NULL)
        return;
    if(root->val==ele)
    {
        floor=root->val;
        return;
    }
    else if(root->val<ele)
    {
        floor=root->val;
        solve(root->right,ele,floor);
    }
    else
        solve(root->left,ele,floor);
}

int floorInBST(TreeNode<int> * root, int X)
{
    int ans=INT_MAX;
    solve(root,X,ans);
    return ans;
}