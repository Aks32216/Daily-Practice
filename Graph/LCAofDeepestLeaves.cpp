class Solution {
public:

    TreeNode* lD;
    TreeNode* rD;

    void solveLeft(int curDepth,int& maxDepth,TreeNode* root)
    {
        if(root==NULL)
            return;
        if(curDepth>maxDepth)
        {
            maxDepth=curDepth;
            lD=root;
        }
        solveLeft(curDepth+1,maxDepth,root->left);
        solveLeft(curDepth+1,maxDepth,root->right);
    }

    void solveRight(int curDepth,int& maxDepth,TreeNode* root)
    {
        if(root==NULL)
            return;
        if(curDepth>maxDepth)
        {
            maxDepth=curDepth;
            rD=root;
        }
        solveRight(curDepth+1,maxDepth,root->right);
        solveRight(curDepth+1,maxDepth,root->left);
    }

    TreeNode* LCA(TreeNode* root,TreeNode* left,TreeNode* right)
    {
        if(root==NULL)
            return NULL;
        if(left==root || right==root)
            return root;
        TreeNode* leftSide=LCA(root->left,left,right);
        TreeNode* rightSide=LCA(root->right,left,right);
        if(leftSide!=NULL && rightSide!=NULL)
            return root;
        else if(leftSide!=NULL)
            return leftSide;
        else if(rightSide!=NULL)
            return rightSide;
        else
            return NULL;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxDepth=-1;
        solveLeft(0,maxDepth,root);
        maxDepth=-1;
        solveRight(0,maxDepth,root);
        return LCA(root,lD,rD);
    }
};