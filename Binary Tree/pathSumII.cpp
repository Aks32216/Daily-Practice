void solve(TreeNode* root,int targetSum,vector<int> temp,vector<vector<int> >& res){
    if(root==NULL)
        return;
    if(root->val==targetSum && root->left==NULL && root->right==NULL)
    {
        temp.push_back(root->val);
        res.push_back(temp);
        return;
    }
    temp.push_back(root->val);
    solve(root->left,targetSum-root->val,temp,res);
    solve(root->right,targetSum-root->val,temp,res);
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int> > res;
    vector<int> temp;
    solve(root,targetSum,temp,res);
    return res;
}