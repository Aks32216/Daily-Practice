long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long,vector<long long>,greater<long long> > pq;
        if(root==NULL)
            return -1;
        queue<TreeNode*> q;
        q.push(root);
        int levels=0;
        while(!q.empty())
        {
            long long size=q.size();
            long long sum=0;
            while(size--){
                auto cur=q.front();
                q.pop();
                sum+=cur->val;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            pq.push(sum);
            if(pq.size()>k)
                pq.pop();
            levels++;
        }
        if(levels<k)
            return -1;
        return pq.top();
    }