class Solution {
public:
    
    vector<TreeNode*> solve(int start,int end)
    {
        if(start>end)
            return {NULL};
        if(start==0)
            return {NULL};
        vector<TreeNode*> temp;
        for(int i=start;i<=end;++i)
        {
            vector<TreeNode*> left=solve(start,i-1);
            vector<TreeNode*> right=solve(i+1,end);
            for(int j=0;j<left.size();++j)
            {
                for(int k=0;k<right.size();++k)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];
                    temp.push_back(root);
                }
            }
        }
        return temp;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};