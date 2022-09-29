 Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;++i)
            {
                auto cur=q.front();
                q.pop();
                if(i==size-1)
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