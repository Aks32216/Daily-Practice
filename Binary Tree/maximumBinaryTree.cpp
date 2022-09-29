TreeNode* solve(vector<int>& nums,int start,int end)
    {
        if(start>=end)
            return NULL;
        int maxElement=*max_element(nums.begin()+start,nums.begin()+end);
        int maxElementIndex=max_element(nums.begin()+start,nums.begin()+end)-nums.begin();
        TreeNode* root=new TreeNode(maxElement);
        root->left=solve(nums,start,maxElementIndex);
        root->right=solve(nums,maxElementIndex+1,end);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n);
    }