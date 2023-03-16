// BFS approach

bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool gotNullSoFar = false;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node==NULL){
                gotNullSoFar = true;
            }else{
                if(gotNullSoFar==true) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }

// DFS Approach

bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        return dfsHelper(root, 1, totalNodes);
    }

    int countNodes(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool dfsHelper(TreeNode* root, int idx, int total){
        if(root==NULL) return true;
        if(idx > total) return false;

        return dfsHelper(root->left, 2*idx, total) && dfsHelper(root->right, 2*idx+1, total);
    }