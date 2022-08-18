// Using Priority Queue

void solve(Node* root,int k,priority_queue<int,vector<int>,greater<int> >& pq)
    {
        if(root==NULL)
            return;
        pq.push(root->data);
        if(pq.size()>k)
            pq.pop();
        solve(root->left,k,pq);
        solve(root->right,k,pq);
    }
    
    int kthLargest(Node *root, int K)
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        solve(root,K,pq);
        return pq.top();
    }

    // Using Recursion

    void solve(Node* root,int& k,int& ans)
    {
        if(root==NULL)
            return;
        solve(root->right,k,ans);
        k--;
        if(k==0)
            ans=root->data;
        solve(root->left,k,ans);
    }
    
    int kthLargest(Node *root, int K)
    {
        int ans=-1;
        solve(root,K,ans);
        return ans;
    }