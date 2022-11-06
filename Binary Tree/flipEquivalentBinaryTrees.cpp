bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL || root2==NULL)
            return root1==root2;
        if(root1->val==root2->val){
            if(flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right))
                return true;
            else if(flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left))
                return true;
            else
                return false;
        }
        else
            return false;
    }