// Iterative Way

Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;++i)
            {
                auto cur=q.front();
                q.pop();
                if(i==n-1)
                    cur->next=NULL;
                else
                    cur->next=q.front();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        return root;
    }

    // Recursive Way

    Node* connect(Node* root) {
        if(root==NULL || root->left==NULL || root->right==NULL)
            return root;
        root->left->next=root->right;
        if(root->next!=NULL)
            root->right->next=root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }