class Solution {
public:

    void solve(int curSum,int& sum,TreeNode* root){
        if(root==NULL)
            return;
        curSum=curSum*10+root->val;
        if(root->left==NULL && root->right==NULL){
            sum+=curSum;
            return;
        }
        solve(curSum,sum,root->left);
        solve(curSum,sum,root->right);
    }

    int sumNumbers(TreeNode* root) {
        int sum=0;
        solve(0,sum,root);
        return sum;
    }
};