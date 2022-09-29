/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    /*
    void solve(TreeNode* root,int curLevel,int& maxDepth,int& sum)
    {
        if(root==NULL)
            return;
        if(curLevel>maxDepth)
        {
            maxDepth=curLevel;
            sum=root->val;
        }
        else if(curLevel==maxDepth)
        {
            sum+=root->val;
        }
        solve(root->left,curLevel+1,maxDepth,sum);
        solve(root->right,curLevel+1,maxDepth,sum);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth=-1;
        int curLevel=0;
        int sum=0;
        solve(root,curLevel,maxDepth,sum);
        cout<<maxDepth<<"\n";
        return sum;
    }
    */
    
    int deepestLeavesSum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int maxSum=0;
        while(!q.empty())
        {
            int sum=0;
            int size=q.size();
            while(size--)
            {
                auto cur=q.front();
                q.pop();
                sum+=cur->val;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            maxSum=sum;
        }
        return maxSum;
    }
    
};