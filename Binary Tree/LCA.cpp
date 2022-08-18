bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(node * root, vector < int > & res) {
  node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}


// 2nd Approach

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