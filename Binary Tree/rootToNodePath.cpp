vector<int> res;

void recurse(TreeNode* A,int B,vector<int> temp)
{
    if(A==NULL)
        return;
    temp.push_back(A->val);
    if(A->val==B)
    {
        res=temp;
        return;
    }
    recurse(A->left,B,temp);
    recurse(A->right,B,temp);
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> temp;
    recurse(A,B,temp);
    return res;
}


bool getPath(node * root, vector < int > & arr, int x) {
  // if root is NULL
  // there is no path
  if (!root)
    return false;

  // push the node's value in 'arr'
  arr.push_back(root -> data);

  // if it is the required node
  // return true
  if (root -> data == x)
    return true;

  // else check whether the required node lies
  // in the left subtree or right subtree of
  // the current node
  if (getPath(root -> left, arr, x) ||
    getPath(root -> right, arr, x))
    return true;

  // required node does not lie either in the
  // left or right subtree of the current node
  // Thus, remove current node's value from
  // 'arr'and then return false   
  arr.pop_back();
  return false;
}