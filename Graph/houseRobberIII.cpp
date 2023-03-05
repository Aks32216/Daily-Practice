class Solution {
public:
    
    pair<int,int> solve(TreeNode* root)
    {
        if(root==NULL)
        {
            pair<int,int> p={0,0};
            return p;
        }
        pair<int,int> l=solve(root->left);
        pair<int,int> r=solve(root->right);
        int x=root->val+l.second+r.second;
        int y=max(l.first,l.second)+max(r.first,r.second);
        return {x,y};
    }
    
    int rob(TreeNode* root) {
        pair<int,int> res=solve(root);
        return max(res.first,res.second);
        
    }
};