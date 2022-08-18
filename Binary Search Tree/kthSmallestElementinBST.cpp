// Using Priority Queue

void solve(TreeNode* root,int k,priority_queue<int>& pq)
    {
        if(root==NULL)
            return;
        pq.push(root->val);
        if(pq.size()>k)
            pq.pop();
        solve(root->left,k,pq);
        solve(root->right,k,pq);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        solve(root,k,pq);
        return pq.top();
    }

   // using inorder traversal 

    void solve(TreeNode* root,int& k,int& ans)
    {
        if(root==NULL)
            return;
        solve(root->left,k,ans);
        k--;
        if(k==0)
            ans=root->val;
        solve(root->right,k,ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        solve(root,k,ans);
        return ans;
    }